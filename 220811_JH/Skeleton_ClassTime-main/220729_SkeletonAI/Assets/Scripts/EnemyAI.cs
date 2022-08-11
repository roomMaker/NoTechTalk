using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum EnemyState
{
    None,       // 
    Idle,       // 대기
    Walk,       // 순찰 patrol
    Run,        // 추적 trace
    Attack,     // 공격
    KnockBack,  // 피격 damaged
    Hide        // 은신
}

public class EnemyAI : MonoBehaviour
{
    public EnemyState state;
    public EnemyState prevState = EnemyState.None;

    Animator animator;

    // 이동관련
    Vector3 targetPos;
    float moveSpeed = 1f;
    float rotationSpeed = 1f;

    // 적 탐지 관련
    public GameObject target;
    bool isFindEnemy = false;
    bool isFindPlayer = false;
    Camera eye;
    Plane[] eyePlanes;

    // 공격 충돌 관련
    GameObject weaponCollider;

    // 은신
    DissolveCtrl dissolveCtrl;

    private void Awake()
    {
        DataManager.Instance.SaveGameData();

        MonsterData data = DataManager.Instance.GetMonsterData(2);
        moveSpeed = data.moveSpeed;
        rotationSpeed = data.rotationSpeed;
    }

    // Start is called before the first frame update
    void Start()
    {
        dissolveCtrl = GetComponentInChildren<DissolveCtrl>();
        dissolveCtrl.ChangeState(DissolveCtrl.State.Hide_Off);

        animator = GetComponent<Animator>();
        eye = transform.GetComponentInChildren<Camera>();
        SphereCollider[] sphereColliders = GetComponentsInChildren<SphereCollider>();
        foreach(var sphereCollider in sphereColliders)
        {
            if (sphereCollider.name == "WeaponCollider")
            {
                weaponCollider = sphereCollider.gameObject;
                break;
            }
        }
        weaponCollider.SetActive(false);

        ChangeState(EnemyState.Idle);
    }

    // Update is called once per frame
    void Update()
    {
        switch(state)
        {
            case EnemyState.Idle: UpdateIdle(); break;
            case EnemyState.Walk: UpdateWalk(); break;
            case EnemyState.Run: UpdateRun(); break;
            case EnemyState.Attack: UpdateAttack(); break;
            case EnemyState.KnockBack: UpdateKnockBack(); break;
            case EnemyState.Hide: UpdateHide(); break;
        }
    }

    #region UpdateDetail
    // 매 프레임마다 수행해야 하는 동작 (상태가 바뀔 때 마다)
    void UpdateIdle()
    {

    }
    public void UpdateWalk()
    {
        if (IsFindEnemy())
        {
            ChangeState(EnemyState.Run);
            return;
        }

        // 목적지까지 이동하는 코드
        Vector3 dir = targetPos - transform.position;
        if (dir.sqrMagnitude <= 0.2f)
        {
            ChangeState(EnemyState.Idle);
            return;
        }

        var targetRotation = Quaternion.LookRotation(targetPos - transform.position, Vector3.up);
        transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, rotationSpeed * Time.deltaTime);

        transform.position += transform.forward * moveSpeed * Time.deltaTime;
    }
    void UpdateRun()
    {
        // 목적지까지 이동하는 코드
        Vector3 dir = targetPos - transform.position;
        //Debug.Log("타겟거리 : " + dir.magnitude);
        if (dir.magnitude <= 2.0f)
        {
            ChangeState(EnemyState.Attack);
            return;
        }

        var targetRotation = Quaternion.LookRotation(targetPos - transform.position, Vector3.up);
        transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, rotationSpeed * 2f * Time.deltaTime);

        transform.position += transform.forward * moveSpeed * 2f * Time.deltaTime;
    }
    void UpdateAttack()
    {

    }
    void UpdateKnockBack()
    {

    }
    void UpdateHide()
    {

    }
    #endregion


    #region CoroutineDetail
    IEnumerator CoroutineIdle()
    {
        // 한번만 수행해야 하는 동작 (상태가 바뀔 때 마다)
        Debug.Log("대기 상태 시작");
        animator.SetBool("isIdle", true);

        while (true)
        {
            yield return new WaitForSeconds(2f);
            // 시간마다 수행해야 하는 동작 (상태가 바뀔 때 마다)
            ChangeState(EnemyState.Hide);
            yield break;            
        }
    }
    IEnumerator CoroutineWalk()
    {
        // 한번만 수행해야 하는 동작 (상태가 바뀔 때 마다)
        Debug.Log("순찰 상태 시작");
        animator.SetBool("isWalk", true);
        dissolveCtrl.ChangeState(DissolveCtrl.State.Hide_Off);

        // 목적지 설정
        targetPos = transform.position + new Vector3(Random.Range(-7f, 7f), 0f, Random.Range(-7f, 7f));

        while (true)
        {
            yield return new WaitForSeconds(10f);
            // 시간마다 수행해야 하는 동작 (상태가 바뀔 때 마다)
            ChangeState(EnemyState.Idle);
        }
    }
    IEnumerator CoroutineRun()
    {
        // 한번만 수행해야 하는 동작 (상태가 바뀔 때 마다)
        if(isFindPlayer == true)
        {
            Debug.Log("추적 상태 시작");
            animator.SetBool("isRun", true);
            targetPos = target.transform.position;

            dissolveCtrl.ChangeState(DissolveCtrl.State.Hide_Off);

            while (true)
            {
                yield return new WaitForSeconds(5f);
                // 시간마다 수행해야 하는 동작 (상태가 바뀔 때 마다)

            }
        }
        
    }
    IEnumerator CoroutineAttack()
    {
        // 한번만 수행해야 하는 동작 (상태가 바뀔 때 마다)
        animator.SetTrigger("isAttack");

        yield return new WaitForSeconds(1f);
        ChangeState(EnemyState.Idle);
        yield break;
    }
    IEnumerator CoroutineKnockBack()
    {
        // 한번만 수행해야 하는 동작 (상태가 바뀔 때 마다)

        while (true)
        {
            yield return new WaitForSeconds(2f);
            // 시간마다 수행해야 하는 동작 (상태가 바뀔 때 마다)

        }
    }
    IEnumerator CoroutineHide()
    {
        // 한번만 수행해야 하는 동작 (상태가 바뀔 때 마다)
        dissolveCtrl.ChangeState(DissolveCtrl.State.Hide_On);

        yield return new WaitForSeconds(3f);
        ChangeState(EnemyState.Walk);
        yield break;
    }
    #endregion

    void ChangeState(EnemyState nextState)
    {
        if (prevState == nextState) return;

        StopAllCoroutines();

        prevState = state;
        state = nextState;
        animator.SetBool("isIdle", false);
        animator.SetBool("isWalk", false);
        animator.SetBool("isRun", false);
        animator.SetBool("isAttack", false);
        animator.SetBool("isKnockBack", false);

        switch (state)
        {
            case EnemyState.Idle: StartCoroutine(CoroutineIdle()); break;
            case EnemyState.Walk: StartCoroutine(CoroutineWalk()); break;
            case EnemyState.Run: StartCoroutine(CoroutineRun()); break;
            case EnemyState.Attack: StartCoroutine(CoroutineAttack()); break;
            case EnemyState.KnockBack: StartCoroutine(CoroutineKnockBack()); break;
            case EnemyState.Hide: StartCoroutine(CoroutineHide()); break;
        }
    }

    bool IsFindEnemy()
    {
        if (!target.activeSelf)
        {
            return false;
        }
        else if (isFindPlayer)
        {
            Bounds targetBounds = target.GetComponentInChildren<SkinnedMeshRenderer>().bounds;
            eyePlanes = GeometryUtility.CalculateFrustumPlanes(eye);
            isFindEnemy = GeometryUtility.TestPlanesAABB(eyePlanes, targetBounds);

            return isFindEnemy;
        }
        else
        {
            return false;
        }
    }

    void OnAttack(AnimationEvent animationEvent)
    {
        Debug.Log("OnAttack() : " + animationEvent.intParameter);  
        if (animationEvent.intParameter == 1)
        {
            weaponCollider.SetActive(true);
        }
        else
        {
            weaponCollider.SetActive(false);
        }
    }

    private void OnCollisionStay(Collision collision)
    {
        if (collision.collider.CompareTag("Player"))
        {
            isFindPlayer = true;
        }
    }

    private void OnCollisionExit(Collision collision)
    {
        if (collision.collider.CompareTag("Player"))
        {
            isFindPlayer = false;
        }
    }
}
