using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class targetmove : MonoBehaviour
{

    private NavMeshAgent agent;

    public GameObject player;

    public float followdistance = 10.0f;//dist [from player] at which to start following player
    public float stopdistance = 4.0f;//dist [from player] at which to not get any closer to player
    public float movementspeed = 5.0f;//speed of 'target'

    // Start is called before the first frame update
    void Start()
    {
        agent = GetComponent<NavMeshAgent>();

        agent.speed = movementspeed;
    }

    // Update is called once per frame
    void Update()
    {
        float distance = Vector3.Distance(transform.position, player.transform.position); //get distance to player

        if(distance >= stopdistance && distance <= followdistance)//if player is within stop/follow distance, begin pathing towards him // need to put shoot in diff method or wont shoot when close
        {
            Vector3 lookdir = transform.position - player.transform.position;
            Vector3 pos = transform.position - lookdir;

            agent.SetDestination(pos);
        }
    }

}
