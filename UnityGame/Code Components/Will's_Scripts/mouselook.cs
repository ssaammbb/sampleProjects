using System.Collections;
using System.Collections.Generic;
using System.Threading;
using UnityEngine;

public class mouselook : MonoBehaviour
{
    //float to change mouse sensitivity multiplier [f indicates float instead of double, double is default in c# as float type]
    public float mouseSensitivity = 200f;

    public Transform playerBody; //players transform info

    float xRotation = 0f; //float value for storing rotation around x axis

    // Start is called before the first frame update
    void Start()
    {
        //hides and locks cursor to screen
        Cursor.lockState = CursorLockMode.Locked;
    }

    // Update is called once per frame
    void Update()
    {
        //floats mousex/y to track mouse movement, * mousesens to adjust to sens value, * deltatime [=time since last fram update] so fps does not effect the sensitivity
        float mouseX = Input.GetAxis("Mouse X") * mouseSensitivity * Time.deltaTime;
        float mouseY = Input.GetAxis("Mouse Y") * mouseSensitivity * Time.deltaTime;

        playerBody.Rotate(Vector3.up * mouseX); //rotate player by mousex on y axis

        //system for rotation around x, do this way instead of .rotate so it can be clamped
        xRotation -= mouseY; //adjust the xrot float by mouseY [+ is inverted]
        xRotation = Mathf.Clamp(xRotation, -90f, 90f); //block rotation from exceeding +/- 90 deg [over head/under feet]

        transform.localRotation = Quaternion.Euler(xRotation, 0f, 0f); //rotate player by mousey on x axis
    }
}
