using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class mainmenu : MonoBehaviour
{
    public Text currUser;

    void Start()
    {
        
    }

    void Update()
    {
        currUser.text = "Current User: " + GameData.Instance.score.playerName;
    }

    public void loadLogin()
    {
        SceneManager.LoadScene(1);
    }

    public void loadPlay()
    {
        SceneManager.LoadScene(3);
    }
}
