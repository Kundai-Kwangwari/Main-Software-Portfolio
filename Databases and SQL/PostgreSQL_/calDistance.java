package calDistance;
import java.sql.Connection;

import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;



public class calDistance {

	public static void main(String args[]) throws SQLException {

        try(Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/postgres","postgres","1234")){
            Class.forName("org.postgresql.Driver");


            
            if(connection != null)
            	System.out.println("Connection successful");
            else System.out.println("Connection failed");
         
            Statement stmt = connection.createStatement();
            
            String query = "SELECT a.Address as src, b.Address as dst,ST_Distance(a.geom::geography,b.geom::geography) As distance FROM Address a, Address b WHERE a.Address  != b.Address";   
            ResultSet rst = stmt.executeQuery(query);
            System.out.println("Calculations done");
            while(rst.next()) {
            	System.out.println("station "+rst.getString("src")+" --> station "+rst.getString("dst")+" is "+rst.getFloat("distance"));
            }
            
        
                    // C:\Users\kunda\Sync\HW\Database Systems\ex01\inputfile.csv
                    
                  
            stmt.close();
            connection.close();
            System.out.println("Connection closed");
                }
         
  
            
           
         catch (ClassNotFoundException e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

}

