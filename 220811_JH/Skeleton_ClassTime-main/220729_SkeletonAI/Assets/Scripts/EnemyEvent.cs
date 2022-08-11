using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyEvent : MonoBehaviour
{
    private Vector3 _target;
    private EnemyAI _enemyAI;
    public Transform _player;
    private bool _isMove;
    private void Start()
    {
        _enemyAI = GetComponent<EnemyAI>();
    }

    private void Update()
    {
         _target = _player.position - transform.position;

        if(_isMove == true)
        {
            Vector3 dir = _target - transform.position;
            if (dir.sqrMagnitude <= 0.2f)
            {
                //_enemyAI.state = EnemyState.Run;
                return;
            }

            var targetRotation = Quaternion.LookRotation(_target - transform.position, Vector3.up);
            transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, 1f * Time.deltaTime);

            transform.position += transform.forward * 1f * Time.deltaTime;
            //transform.rotation = Quaternion.LookRotation(_target);
        }

    }

    private void OnCollisionEnter(Collision collision)
    {
        if(collision.collider.CompareTag("Player"))
        {
            Debug.Log("Àû¿¡°Ô ´êÀ½");
            _enemyAI.state = EnemyState.Attack;
        }
    }
    public void MoveToPlayer()
    {
        Debug.Log("movetoÇÔ¼ö È£ÃâµÊ");
        _isMove = true;
    }
}
