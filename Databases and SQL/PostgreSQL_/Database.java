import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Database {

	public static void main(String args[]) {

        try(Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/postgres","postgres","1234")){
            Class.forName("org.postgresql.Driver");

            //System.out.println("Input file path:");
            String path = "C:\\Users\\kunda\\Sync\\HW\\Database Systems\\ex01\\inputfile.csv";
            /*try (Scanner scanner = new Scanner(System.in)) {
                path = scanner.nextLine();
            }*/

            String line = "";
            int countRows = 0;
           
            
            if(connection != null)
            	System.out.println("Connection successful");
            else System.out.println("Connection failed");
         
            Statement stmt = connection.createStatement();
            
            String query = "create table Airpollution(code int, Date date, hour int, SO2 float, NO float, NO2 float, NOx float,"
            		+ "CO float, Ox float, NMHC FLOAT, CH4 FLOAT, THC FLOAT, SPM float, PM2_5 float,SP float,"
            		+ " WD varchar, WS float, TEMP float, HUM float)";   
            stmt.executeUpdate(query);
            
        
            
           
            try {
                // parsing a CSV file into BufferedReader class constructor
                BufferedReader br = new BufferedReader(new FileReader(path));
                for (int i = 0; i < 1; i++) {

                    if ((line = br.readLine()) != null) {// returns a Boolean value

                        String[] columnHeaders = line.split(",", -1);
                        int countColumns = columnHeaders.length;
                    }
                }

                BufferedReader dr = new BufferedReader(new FileReader(path));
                while ((line = dr.readLine()) != null) {
                    countRows++;
                    String[] data = line.split(",", -1); // use comma as separator
                    
                    for(int i = 0; i < data.length; i++) {
                    	if(data[i] == "") {
                    		data[i] = "0.0";
                    	}
                    }
                    	
                    
                    
                    //this commented out section is to check output of the read file.
                    /*if (countRows != 1) {
                    System.out.println(Integer. parseInt(data[0])+","+data[1]+","+Integer. parseInt(data[2])+","+Double. parseDouble(data[3])+","
                    		+ ""+Double. parseDouble(data[4])+","+Double. parseDouble(data[5])+","+Double. parseDouble(data[6])+","+Double. parseDouble(data[7])+","
                    				+ ""+Double. parseDouble(data[8])+","+Double. parseDouble(data[9])+","+Double. parseDouble(data[10])+","
                    		+Double. parseDouble(data[11])+","+Double. parseDouble(data[12])+","+Double. parseDouble(data[13])+","+Double. parseDouble(data[14])+","
                    				+data[15]+","+Double. parseDouble(data[16])+","+Double. parseDouble(data[17])+","+Double. parseDouble(data[18]));
                    }*/
                    // C:\Users\kunda\Sync\HW\Database Systems\ex01\inputfile.csv
                    
                    if (countRows != 1) {
                        query = "insert into Airpollution(code, Date, hour, SO2, NO, NO2, NOx,CO, Ox, NMHC, CH4, THC, SPM, PM2_5,SP,WD, WS, TEMP, HUM)"
                        		+ " values("+Integer. parseInt(data[0])+",'"+data[1]+"',"+Integer.parseInt(data[2])+","+Float.parseFloat(data[3])+","
                        		+ ""+Float.parseFloat(data[4])+","+Float.parseFloat(data[5])+","+Float.parseFloat(data[6])+","+Float.parseFloat(data[7])+","
                				+ ""+Float.parseFloat(data[8])+","+Float.parseFloat(data[9])+","+Float.parseFloat(data[10])+","
                		+Float.parseFloat(data[11])+","+Float.parseFloat(data[12])+","+Float.parseFloat(data[13])+","+Float.parseFloat(data[14])+",'"
                				+data[15]+"',"+Float.parseFloat(data[16])+","+Float.parseFloat(data[17])+","+Float.parseFloat(data[18])+")";
                        stmt.executeUpdate(query);
                    
                    
                    }
                   
                }
                    
                
            } catch (IOException e) {
                e.printStackTrace();

            }
  
            
            stmt.close();
            connection.close();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

}
