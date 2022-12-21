import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Stations_Read {

	public static void main(String[] args) throws IOException, SQLException, ClassNotFoundException {
		// TODO Auto-generated method stub
		
        try(Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/postgres","postgres","1234")){
            Class.forName("org.postgresql.Driver");

            //System.out.println("Input file path:");
            String path = "C:\\Users\\kunda\\Sync\\HW\\Database Systems\\ex4.2\\station.csv";
            /*try (Scanner scanner = new Scanner(System.in)) {
                path = scanner.nextLine();
            }*/

            String line = "";
            int countColumns = 0;
            int countRows = 0;
           
            
           if(connection != null)
            	System.out.println("Connection successful");
            else System.out.println("Connection failed");
         
            Statement stmt = connection.createStatement();
            
            String query = "create table Address(serialnumber int, stationID int, geom geometry, Address varchar)";   
            stmt.executeUpdate(query);
            System.out.println("Table created");
            
            // parsing a CSV file into BufferedReader class constructor
			BufferedReader br = new BufferedReader(new FileReader(path));
			for (int i = 0; i < 1; i++) {

			    if ((line = br.readLine()) != null) {// returns a Boolean value

			        String[] columnHeaders = line.split(",", -1);
			        countColumns = columnHeaders.length;
			    }
			}

			BufferedReader dr = new BufferedReader(new FileReader(path));
			while ((line = dr.readLine()) != null) {
			    countRows++;
			    String[] data = line.split(",", -1); // use comma as separator
			    
			    /*for(int i = 0; i < data.length; i++) {
			    	if(data[i] == "") {
			    		data[i] = "0.0";
			    	}
			    }*/
			    
			    
			    	System.out.println("data[0]: "+data[0]+" |data[1]: "+data[1]+"|data[2]: "+data[2]+" |data[3]: "+data[3]);
			    
			    	 
	                        query = "insert into Address(serialnumber, stationID, geom , Address)"
	                        		+ " values("+Integer.parseInt(data[0])+","+Integer.parseInt(data[1])+",'"+data[2]+"','"+(data[3])+"')";
	                        stmt.executeUpdate(query);
	                    
	                    
	                   

					}
			  stmt.close();
	           connection.close();
        }
	}
}
