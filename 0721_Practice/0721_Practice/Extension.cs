using UnityEngine;
public static class Extension
{
    public static void SetIKPositionAndWeight(this Animator animator, AvatarIKGoal goal, Vector3 goalPosition, float weight = 1f)
    {
        animator.SetIKPositionAndWeight(goal, goalPosition);
        animator.SetIKPosition(goal, goalPosition);
    }
}