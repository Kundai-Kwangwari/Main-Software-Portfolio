import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class AviationData {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	        try(Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/aviationdata","postgres","1234")){
	            Class.forName("org.postgresql.Driver");

	            //System.out.println("Input file path:");
	            String path = "C:\\Users\\kunda\\Sync\\HW\\Database Systems\\ex8\\aviationData.txt";
	            /*try (Scanner scanner = new Scanner(System.in)) {
	                path = scanner.nextLine();
	            }*/

	            String line = "";
	            int countRows = 0;
	           
	            
	            if(connection != null)
	            	System.out.println("Connection successful");
	            else System.out.println("Connection failed");
	         
	            Statement stmt = connection.createStatement();
	            
	            
	            String query = "create table EventDetails(Accident_number varchar PRIMARY KEY, EventID varchar, Location varchar,	Airport_name varchar, Country varchar, latitude varchar, longitude varchar,"
	            		+ "Investigation_type varchar, Airport_code varchar )";
	            stmt.executeUpdate(query);
	            query = "create table GeneralData(Accident_number varchar, Aircarrier varchar, Schedule varchar, Purpose_of_flight varchar, FAR_description varchar, Date date, "
	            		+ "Aircraft_damage varchar, injury_severity varchar, Total_uninjured int, Total_minor_injuries int, Total_fatal_injuries int, Total_serious_injuries int,	"
	            		+ "Weather_condition varchar, Broad_Phase_of_flight varchar, Report_status varchar, Publication_date date, FOREIGN KEY(Accident_number) references EventDetails(Accident_number))";
	            stmt.executeUpdate(query);
	            query = "create table AirplaneInfo(Accident_number varchar, Registration_number varchar, Aircraft_category varchar, Make varchar, Model varchar, Amateur_built varchar, Number_of_engines int, Engine_type varchar, FOREIGN KEY(Accident_number) references EventDetails(Accident_number))";
	            stmt.executeUpdate(query);
	            
	            
	           
	            try {
	                // parsing a CSV file into BufferedReader class constructor
	                BufferedReader br = new BufferedReader(new FileReader(path));
	                for (int i = 0; i < 1; i++) {

	                    if ((line = br.readLine()) != null) {// returns a Boolean value

	                        
	                        String[] columnHeaders = line.split("|", -1);
	                        int countColumns = columnHeaders.length;
	                        
	                    }
	                }

	                BufferedReader dr = new BufferedReader(new FileReader(path));
	                while ((line = dr.readLine()) != null) {
	                    countRows++;
	                    
	                    if(countRows == 1)continue;
	                    //System.out.println(line);
	                    line = line.replace("|", "~"); // use comma as separator
	                    line = line.replace("'", "''");
	                    //System.out.println(line);
	                    String[] data = line.split("~", -1);
	                    
	                    
	                    for(int i = 0; i < data.length; i++) {
	                    	data[i] = data[i].trim();
	                    	if(data[i] == "") {
	                    		data[i] = "0";
	                    	}
	                    	//System.out.print("  "+i+".-->"+data[i]);
	                    }
	                    	
	                    
	                
	                    
	                   if(data[30] != "0") { //cannot insert null date into postgresql database
	                    
	                        query = "insert into  EventDetails(Accident_number, EventID, Location, Airport_name, Country, latitude, longitude, Investigation_type, Airport_code)"
	                        + " values('"+data[2]+"','"+data[0]+"','"+data[4]+"','"+data[9]+"','"+data[5]+"','"+data[7]+"','"+data[6]+"','"+data[1]+"','"+data[8]+"')";
	                        stmt.executeUpdate(query);
	                        //System.out.println("EventDetails okay");
	                    
	                        query = "insert into GeneralData( Accident_number, Aircarrier, Schedule , Purpose_of_flight , FAR_description, Date, Aircraft_damage,"
	                        		+ " injury_severity, Total_uninjured, Total_minor_injuries, Total_fatal_injuries, Total_serious_injuries, Weather_condition,"
	                        		+ " Broad_Phase_of_flight, Report_status, Publication_date)"
	                        		+ " values('"+data[2]+"','"+data[22]+"','"+data[20]+"','"+data[21]+"','"+data[19]+"','"+data[3]+"','"+data[11]+"','"+data[10]+"'"
	                        				+ ","+Integer.parseInt(data[26])+","+Integer. parseInt(data[25])+","+Integer. parseInt(data[23])+","+Integer. parseInt(data[24])+",'"+data[27]+"','"+data[28]+"','"+data[29]+"','"+data[30]+"' )";
	                        stmt.executeUpdate(query);
	                        //System.out.println("GeneralData okay");
	                        
	                        query = "insert into AirplaneInfo(Accident_number,Registration_number, Aircraft_category, Make, Model , Amateur_built, Number_of_engines, Engine_type)"
	                        		+ " values('"+data[2]+"','"+data[13]+"','"+data[12]+"','"+data[14]+"','"+data[15]+"',"
	                        		+ "'"+data[16]+"',"+Integer.parseInt(data[17])+",'"+data[18]+"')";
	                        stmt.executeUpdate(query);
	                        //System.out.println("\nAirplane okay");
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
