using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Data.Sql;
using System.Data.SqlClient;
using UnityEngine;
using System.Data;
using System;

public class testSql : MonoBehaviour
{
    
    /*string conString = "Server=localhost;" +
        "Database=football_db;" +
        "User ID=postgres;" +
        "Password=Leonesiois1!2314;";
    */
    // Start is called before the first frame update
    void Start()
    {

        SqlConnection sqlcon = new SqlConnection(@"Data Source = (local)\Sqle2012;Initial Catalog=football_db;User ID =postgres;Password=Leonesiois1!2314;");
        //SqlConnection sqlcon = new SqlConnection(conString);
        SqlDataAdapter sqlda = new SqlDataAdapter("Select * from football_games",sqlcon);
        DataTable dtbl = new DataTable();
        sqlda.Fill(dtbl);
        /*foreach(DataRow row in dtbl.Rows)
        {
            Debug.Log(row["visitor_name"]);
        }
        */

    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
