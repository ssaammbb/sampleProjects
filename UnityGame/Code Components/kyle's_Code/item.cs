using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class item : MonoBehaviour
{
    public string uniqueName;
    public int maxstack;



    void Start()
    {
        GameObject.FindGameObjectsWithTag("Player"); //find the player so it knows all the info about them
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        if (this.gameObject.layer != 5)
        {
            foreach (GameObject player in GameObject.FindGameObjectsWithTag("Player"))
            {
                if ((player.transform.position - this.transform.position).sqrMagnitude < 10)//test if play is in rage to pick item up
                {
                    if (FindObjectsOfType<inventoryManager>()[0].addObject(this.gameObject))
                    {

                        break;
                    }
                }
            }
        }
    }
}
