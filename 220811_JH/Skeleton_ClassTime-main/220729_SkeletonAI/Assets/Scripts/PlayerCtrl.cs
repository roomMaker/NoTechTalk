using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Assets;

public class PlayerCtrl : MonoBehaviour, ITargetable
{
    private CharacterController _control;
    private Rigidbody _rb;
    private float _moveSpeed = 5f;
    private float _inputX;
    private float _inputY;
    private Vector3 _move;
    private void Start()
    {
        _control = GetComponent<CharacterController>();
        _rb = GetComponent<Rigidbody>();
    }

    private void Update()
    {
        _inputX = Input.GetAxisRaw("Horizontal");
        _inputY = Input.GetAxisRaw("Vertical");
        _move = new Vector3(_moveSpeed * _inputX * Time.deltaTime, -30f * Time.deltaTime, _moveSpeed * _inputY * Time.deltaTime);
        _control.Move(_move);
        
    }
    public void Damaged()
    {
        Debug.Log("공격을 받았다");
    }

    
}
