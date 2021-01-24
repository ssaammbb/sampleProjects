using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Npgsql;

public class PlayerScore 
{
    public int score = 0;
    public string playerName = "Anonymous";
    public void submitScore()
    {
        string cs = "Host=ec2-54-84-98-18.compute-1.amazonaws.com; Username =rzwgdueiiqelyf; Password =a6c3efbd67d5b34c2a182adb4faf6e418143f7e3eb6d69899a3d1d175be30c8a; Database =d54dd8qjq3nktf; SSL =true;SslMode=Require;";
        NpgsqlConnection con;
        con = new NpgsqlConnection(cs);
        con.Open();

        // var sql = "SELECT version()";
        string sql = "INSERT INTO high_score (score, username) VALUES("+score+",'"+playerName+"')";

        NpgsqlCommand cmd = new NpgsqlCommand(sql, con);

        cmd.ExecuteScalar();
        Debug.Log("done");
    }
}
