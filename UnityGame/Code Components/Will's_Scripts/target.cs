//using System.Collections;
//using System.Collections.Generic;
using System.Collections;
using UnityEngine;

public class target : MonoBehaviour
{

    public float health = 50f;
    Material mat;
    
    void Start()
    {
        mat = GetComponent<MeshRenderer>().material; //set mat as current obj material
        mat.color = Color.blue;
    }

    void Update()
    {

    }

    public void TakeDamage(float amount)
    {
        mat.color = Color.red; //set color to red on hit

        health -= amount;
        if (health <= 0f)
        {
            Die();
        }


        Invoke("resetmat", 1); //reset material color after 1s delay [note: if done this way and you shoot at ms=0000 and again at ms=(001,999) then resetmat still occurs at ms=1000 rather than ms=(1001,1999)
    }

    void resetmat()
    {
        mat.color = Color.blue;
    }

    void Die()
    {
        GameData.Instance.addScore(100);
        Destroy(gameObject);
    }

}
