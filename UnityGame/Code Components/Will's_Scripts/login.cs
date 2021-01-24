using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Npgsql;
using UnityEngine.SceneManagement;

public class login : MonoBehaviour
{
    public static string loggedinas = "";
    
    public InputField usernameField;
    public InputField passwordField;

    public Button submitButton;

    public Text statustext;
    public Text currUser;

    public void runLogin()
    {
        string username = usernameField.text.ToString();
        string password = passwordField.text.ToString();

        //note this is set up on a test login table currently, need to update this once table for website-registration is done
        //Also this is raw text password sending/storage, this is super duper not secure.
        string sql = "SELECT username, password FROM login WHERE username='" + username + "' AND password='" + password + "';";

        string cs = "Host=ec2-54-84-98-18.compute-1.amazonaws.com; Username =rzwgdueiiqelyf; Password =a6c3efbd67d5b34c2a182adb4faf6e418143f7e3eb6d69899a3d1d175be30c8a; Database =d54dd8qjq3nktf; SSL =true;SslMode=Require;";
        NpgsqlConnection con;
        con = new NpgsqlConnection(cs);
        con.Open();

        NpgsqlCommand cmd = new NpgsqlCommand(sql, con);
        string output = (string)cmd.ExecuteScalar();
        if (output == username){
            UnityEngine.Debug.Log($"login successful");
            loggedinas = username;
            GameData.Instance.score.playerName = loggedinas;
            statustext.text = "Login Successful.";
            currUser.text = "Current User: " + loggedinas;
        }
        else{
            UnityEngine.Debug.Log($"login unsuccessful");
            statustext.text = "Login Failed. Incorrect Username or Password.";
        }
    }
    //attached to input fields, on edit run this method (checks if fields contain something)
    public void VerifyInputs(){
        submitButton.interactable = (usernameField.text.Length >= 1
            && passwordField.text.Length >= 1);
    }

    public void loadMainMenu()
    {
        SceneManager.LoadScene(0);
    }
}
