using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;
public class PlayerEvent : MonoBehaviour
{
    public UnityEvent attackEnemy;
    private EnemyEvent _enemy;

    private void Start()
    {
        _enemy = GetComponent<EnemyEvent>();
    }
    private void OnCollisionEnter(Collision collision)
    {
        if(collision.collider.CompareTag("Enemy"))
        {
            attackEnemy.Invoke();   
            //_enemy.MoveToPlayer();
        }
    }

    
}
