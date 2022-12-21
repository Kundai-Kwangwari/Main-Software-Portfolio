import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.management.Query;


public class Extract_Text {

	public static void main(String args[]) throws SQLException, IOException, ClassNotFoundException {

        try(Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/postgres","postgres","1234")){
            Class.forName("org.postgresql.Driver");

            FileWriter myWriter = new FileWriter("raw.txt"); 
            
           
            
            if(connection != null)
            	System.out.println("Connection successful");
            else System.out.println("Connection failed");
         
            Statement stmt = connection.createStatement();
            
            //String query = "select * from Airpollution"; 
            //String query = "alter table airpollution rename column pm2_5 to pm25";
            //stmt.executeUpdate(query);
            String query  = "select array_agg(distinct(code)) as data from airpollution where pm25>=35 group by date order by date asc";
            ResultSet rst = stmt.executeQuery(query);
            System.out.println("fetch done...");
            while(rst.next()) {
            	//System.out.println(rst.getString("data"));
            	 myWriter.write(rst.getString("data"));
       	      
            }
            
            
                    // C:\Users\kunda\Sync\HW\Database Systems\ex01\inputfile.csv
                    
            myWriter.close();   
            
            
            stmt.close();
            connection.close();
                }
         
        try {
        	List<String> lines = new ArrayList<String>();
            String line = null;
        	String path = "C:\\Users\\kunda\\eclipse-workspace\\Extract_Text\\raw.txt";
        	 
        	
             BufferedReader br = new BufferedReader(new FileReader(path));
             while ((line = br.readLine()) != null) {
                 if (line.contains("{")) {
                     line = line.replace("{", "\t");
                     line = line.replace(",", "\t");
                     line = line.replace("}", "\t");
                 lines.add(line);
             }
             }

             br.close();

        	FileWriter fw = new FileWriter("filename.txt");
             BufferedWriter out = new BufferedWriter(fw);
             for(String s : lines)
                  out.write(s);
             out.flush();
             out.close();
             File raw = new File(path);
             raw.delete();
             System.out.println("Successfully wrote to the filename.txt");
           }catch (Exception ex) {
        	    ex.printStackTrace();
        }
    }	
	
	
}


	