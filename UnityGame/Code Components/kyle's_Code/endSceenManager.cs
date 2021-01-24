using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public class endSceenManager : MonoBehaviour
{
    public UnityEngine.UI.Text Score;
    void Start()
    {
        Cursor.lockState = CursorLockMode.None;
        Score.text = "Score:" + GameData.Instance.score.score;
    }



    // Update is called once per frame
    public void submiteScore()
    {
    
        GameData.Instance.score.submitScore();
        Application.Quit();
    }
}
