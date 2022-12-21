
	import java.sql.Connection;
	import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
	import java.sql.Statement;

	import java.io.BufferedReader;
	import java.io.FileReader;
	import java.io.IOException;
	import java.util.Scanner;


	public class JDBC_Read {

		public static void main(String args[]) throws SQLException {

	        try(Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/postgres","postgres","1234")){
	            Class.forName("org.postgresql.Driver");

	            
	            
	           
	            
	            if(connection != null)
	            	System.out.println("Connection successful");
	            else System.out.println("Connection failed");
	         
	            Statement stmt = connection.createStatement();
	            
	            String query = "select * from Airpollution";   
	            ResultSet rst = stmt.executeQuery(query);
	            while(rst.next()) {
	            	System.out.println(rst.getInt("code")+","+rst.getDate("Date")+","+rst.getInt("hour")+","+rst.getFloat("SO2")+","+rst.getFloat("NO")
	            	+","+rst.getFloat("NO2")+","+rst.getFloat("NOx")+","+rst.getFloat("CO")+","+rst.getFloat("Ox")+","+rst.getFloat("NMHC")
	            	+","+rst.getFloat("CH4")+","+rst.getFloat("THC")+","+rst.getFloat("SPM")+","+rst.getFloat("PM2_5")+","+rst.getFloat("SP")+","+rst.getString("WD")
	            	+","+rst.getFloat("WS")+","+rst.getFloat("TEMP")+","+rst.getFloat("HUM"));
	            }
	            
	        
	                    // C:\Users\kunda\Sync\HW\Database Systems\ex01\inputfile.csv
	                    
	                  
	            stmt.close();
	            connection.close();
	                }
	         
	  
	            
	           
	         catch (ClassNotFoundException e) {
	            e.printStackTrace();
	            System.exit(-1);
	        }
	    }

	}
