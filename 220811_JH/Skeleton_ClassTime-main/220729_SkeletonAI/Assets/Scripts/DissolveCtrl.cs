using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DissolveCtrl : MonoBehaviour
{
    public enum State
    {
        Hide_On, Hide_Off
    }

    public State state = State.Hide_Off;
    Material mat;

    // Start is called before the first frame update
    void Start()
    {
        mat = GetComponent<Renderer>().material;
    }

    // Update is called once per frame
    void Update()
    {
        switch(state)
        {
            case State.Hide_On: UpdateHideOn(); break;
            case State.Hide_Off: UpdateHideOff(); break;
        }
    }

    void UpdateHideOn()
    {
        float dissoveAmount = mat.GetFloat("_DissolveAmount");
        if (dissoveAmount < 1f)
        {
            mat.SetFloat("_DissolveAmount", dissoveAmount + (0.5f * Time.deltaTime));
        }
        else
        {
            mat.SetFloat("_DissolveAmount", 1f);
        }
    }
    void UpdateHideOff()
    {
        float dissoveAmount = mat.GetFloat("_DissolveAmount");
        if (dissoveAmount > 0f)
        {
            mat.SetFloat("_DissolveAmount", dissoveAmount - (0.5f * Time.deltaTime));
        }
        else
        {
            mat.SetFloat("_DissolveAmount", 0f);
        }
    }

    public void ChangeState(State _nextState)
    {
        state = _nextState;
    }
}
