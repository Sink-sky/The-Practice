package com.sinksky;

import java.sql.ResultSet;
import java.sql.SQLException;

import javax.swing.JOptionPane;
import javax.swing.table.AbstractTableModel;





@SuppressWarnings("serial")
public class SaleTableModel extends AbstractTableModel{

	SaleFrame self;
	String dbname = "salesystem";
	String tbname;
	String searchitem = "*";
	String searchvalue = "*";
	
	SaleTableModel(SaleFrame sf,String tb){
		this.self = sf;
		this.tbname = tb;
	}
	
	public SaleTableModel(SaleFrame sf,String tb,String item,String value) {
		this.self = sf;
		this.tbname = tb;
		this.searchitem = item;
		this.searchvalue = value;
	}
	
	@Override
	public int getRowCount() {
		int num = 0;
		try {
			if(searchitem.equals("*"))
				num = SQLServer.getrownum(tbname);
			else
				num = SQLServer.getrownum(tbname,searchitem, searchvalue);
		} catch (SQLException e) {
			e.printStackTrace();	
			JOptionPane.showMessageDialog(self, "数据库错误", "warning", JOptionPane.WARNING_MESSAGE);
		}
		return num;
	}

	@Override
	public int getColumnCount() {
		int num = 0;
		try {
			num = SQLServer.getcolnum(dbname,tbname);
		} catch (SQLException e) {
			e.printStackTrace();
			JOptionPane.showMessageDialog(self, "数据库错误", "warning", JOptionPane.WARNING_MESSAGE);
		}
		return num;
	}
	
	@Override
	public String getColumnName(int columnIndex) {
		try {
			return SQLServer.getcolname(tbname, columnIndex);
		} catch (SQLException e) {
			e.printStackTrace();
			JOptionPane.showMessageDialog(self, "数据库错误", "warning", JOptionPane.WARNING_MESSAGE);
		}
		return null;
	}
	 
	@Override
	public boolean isCellEditable(int rowIndex, int columnIndex) {
		if(getColumnName(columnIndex).equals("time"))
			return false;
		if(self.getJMenuBar() == self.MANAGEMENUBAR)
			return true;
		else
			return false;
//        return true;
    }
	
	@Override
	public Object getValueAt(int rowIndex, int columnIndex) {
		String sitem = getColumnName(columnIndex);
		try {
			if(this.searchitem.equals("*")) {
				ResultSet rSet;
				rSet = SQLServer.stat.executeQuery("select "+sitem+" from "+tbname);
				for(int i = 0;i <= rowIndex;++i)
					rSet.next();
				return rSet.getString(sitem);
			}
			else {
				ResultSet rSet = SQLServer.search(tbname, searchitem, searchvalue, sitem);
				for(int i = 0;i <= rowIndex;++i)
					rSet.next();
				return rSet.getString(sitem);
			}
		} catch (SQLException e) {
			e.printStackTrace();
			JOptionPane.showMessageDialog(self, "数据库错误", "warning", JOptionPane.WARNING_MESSAGE);
		}
		return null;
	}
	
	@Override
	public void setValueAt(Object aValue, int rowIndex, int columnIndex) {
		try {
			SQLServer.setvalue(tbname, "time", (String)getValueAt(rowIndex, 0), getColumnName(columnIndex),(String) aValue);
		} catch (SQLException e) {
			JOptionPane.showMessageDialog(self, "setValueAt Error", "warning", JOptionPane.WARNING_MESSAGE);
			e.printStackTrace();
		}
		self.ShowStockJT.updateUI();
    }
}
