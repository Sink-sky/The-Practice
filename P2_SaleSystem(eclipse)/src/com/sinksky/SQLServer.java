package com.sinksky;

import java.sql.*;


public class SQLServer {
	//基础设置
	static Connection con;
	static Statement stat;
	final static String DRIVER = "com.mysql.cj.jdbc.Driver";
	final static String USER = "root";
	final static String PASS = "root";
	final static String URL = "jdbc:mysql://localhost:3306/salesystem?serverTimezone=GMT";
	
	//开启关闭
	static void open(){
		try {
			Class.forName(DRIVER);
			con = DriverManager.getConnection(URL,USER,PASS);
			stat = con.createStatement();
		} catch (SQLException | ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	static void close(){
		try {
			stat.close();
			con.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	static int getcolnum(String db,String tb) throws SQLException {
		String Sql = "select count(*) from information_schema.columns where table_schema='"+db+"' and table_name='"+tb+"'";
		ResultSet Rs = stat.executeQuery(Sql);
		Rs.next();
		int count = Rs.getInt("count(*)");
		return count;
	}
	
	static int getrownum(String tb) throws SQLException {
		ResultSet rset = stat.executeQuery("select count(*) totalCount from "+tb); 
		int rowCount = 0; 
		if(rset.next()) { 
		  rowCount=rset .getInt("totalCount"); 
		}
		return rowCount;
	}
	
	static ResultSet search(String table,String keyitem,String keyvalue) {
		String Sql = "select * from " + table + " where " + keyitem + "='" + keyvalue +"'";
		ResultSet Rs = null;
		try {
			Rs = stat.executeQuery(Sql);
		} catch (SQLException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		return Rs;
	}
	
	static int getrownum(String tb,String item,String value) throws SQLException {
		ResultSet rset = search(tb, item, value); 
		int rowCount = 0; 
		while(rset.next()) { 
			++rowCount; 
		}
		return rowCount;
	}
	
	static String getcolname(String tb,int colnum) throws SQLException {
		PreparedStatement pstmt=con.prepareStatement("select * from "+tb);
		java.sql.ResultSetMetaData resultSetData = pstmt.getMetaData();
		return resultSetData.getColumnName(colnum+1);
	}
	
	static ResultSet search(String table,String keyitem,String keyvalue,String searchitem) throws SQLException {
		String Sql = "select " + searchitem +" from " + table + " where " + keyitem + "='" + keyvalue +"'";
		ResultSet Rs = stat.executeQuery(Sql);
		return Rs;
	}
	
	static void setvalue(String table,String keyitem,String keyvalue,String searchitem,String searchvalue) throws SQLException {
		String Sql = "update " + table + " set " + searchitem + " = '" + searchvalue + "' where " + keyitem + " = '" + keyvalue + "'";
		stat.execute(Sql);
	}
	
	static void additem(String table,String[] args) {
		StringBuilder Sql = new StringBuilder("insert into "+table+" values(");
		for(String i:args) {
			if(i != args[0])
				Sql.append(",");
			Sql.append("'"+i+"'");
		}
		Sql.append(")");
		try {
			stat.execute(Sql.toString());
		} catch (SQLException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
	
	static void deletetable(String table) {
		String Sql = "delete from "+table;
		try {
			stat.execute(Sql);
		} catch (SQLException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
	
	static void deleteitem(String table,String key,String keyvalue) {
		String Sql = "delete from "+table +" where " + key + " = '" + keyvalue + "'";
		try {
			stat.execute(Sql);
		} catch (SQLException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
	

	
	
}	
	
