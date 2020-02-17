import java.sql.*;

public class postgreSQLJDBC {
	public static void main(String[] args){
		Connection connc = null;
		Statement stmt = null;
		String url = "jdbc:postgresql://localhost:5432/postgres";
		String userName = "postgres";
		String password = "081849";
		try{
			Class.forName("org.postgresql.Driver");
			connc = DriverManager.getConnection(url,userName,password);
			stmt = connc.createStatement();
			String sql = "select * from assignment";
			ResultSet res = stmt.executeQuery(sql);
			while(res.next()){
				System.out.print(res.getString(1));
				System.out.print(res.getString(2));
				System.out.print(res.getString(3));
				System.out.println(res.getString(4));
			}
			res.close();
			stmt.close();
			connc.close();
		}catch(Exception e){
			System.err.println(e);
		}


	}
}
