package com.sinksky;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTable;


public class SaleEvent implements ActionListener {

	// 添加监听器时将SaleFrame本身传入,使监听器可以访问组件
	SaleFrame SELF;

	public SaleEvent(SaleFrame saleFrame) {
		SELF = saleFrame;
	}

	// 触发事件自动调用函数,在自动调用的函数中做分支选择,调用其它函数.
	@Override
	public void actionPerformed(ActionEvent e) {
		String Command = e.getActionCommand();
//		System.out.println(Command);
		if (Command.equals("登入"))
			login();
		else if(Command.equals("Logout")) 
			actionlogout();
		else if(Command.equals("Register")) 
			actionregister();
		else if(Command.equals("注册")) 
			register();
		else if(Command.equals("Showstock"))
			actionshowstock();
		else if(Command.equals("Showsale"))
			actionshowsale();
		else if(Command.equals("Stockin"))
			actionstockin();
		else if(Command.equals("Searchstock"))
			actionsearchstock();
		else if(Command.equals("Searchsale"))
			actionsearchsale();
		else if(Command.equals("Stockout"))
			actionstockout();
		else if(Command.equals("Saleout"))
			actionsaleout();
		else if(Command.equals("入库"))
			stockin();
		else if(Command.equals("SEARCHSTOCK"))
			searchstock();
		else if(Command.equals("SEARCHSALE"))
			searchsale();
	}
	
	public void login() {
		String Username = SELF.USERNAMEJTF.getText();
		char[] Passwordc = SELF.PASSWORDJPF.getPassword();
		StringBuilder Passwordb = new StringBuilder("");
		for (char i : Passwordc) {
			Passwordb.append(i);
		}
		String Password = Passwordb.toString();
		if(Username.equals("")||Password.equals("")) {
			JOptionPane.showMessageDialog(SELF, "请先完善登陆信息", "warning", JOptionPane.WARNING_MESSAGE);
			return;
		}
		ResultSet Rs = SQLServer.search("user", "username", Username);
		try {
			if(Rs.next()&&Rs.getString("password").equals(Password)) {
				SELF.getContentPane().removeAll();
				if(Rs.getString("competence").equals("MANAGE"))
					SELF.setJMenuBar(SELF.MANAGEMENUBAR);
				else
					SELF.setJMenuBar(SELF.USERMENUBAR);
				SELF.add(SELF.BACKGROUNDJP);
				SELF.USERNAMEJTF.setText("");
				SELF.PASSWORDJPF.setText("");
				SELF.revalidate();
			}
			else {
				JOptionPane.showMessageDialog(SELF, "用户名或密码错误", "warning", JOptionPane.WARNING_MESSAGE);
			}
		} catch (SQLException e) {
			JOptionPane.showMessageDialog(SELF, "数据库错误", "warning", JOptionPane.WARNING_MESSAGE);
			e.printStackTrace();
		}
	}
	
	public void actionregister() {
		SELF.getContentPane().removeAll();
		SELF.add(SELF.REGISTERJP);
		SELF.add(SELF.BACKGROUNDJP);
		SELF.repaint();
	}
	
	public void register() {
		if(SELF.getJMenuBar()==SELF.USERMENUBAR&&SELF.COMPETENCEJCB.getSelectedItem()=="管理员") {
			JOptionPane.showMessageDialog(SELF, "权限不足", "warning", JOptionPane.WARNING_MESSAGE);
			return;
		}
		ResultSet Rs = SQLServer.search("user", "username", SELF.REUSERNAMEJTF.getText());
		try {
			if(Rs.next()) {
				JOptionPane.showMessageDialog(SELF, "用户名已存在", "warning", JOptionPane.WARNING_MESSAGE);
				return;
			}
		} catch (SQLException e) {
			JOptionPane.showMessageDialog(SELF, "数据库连接错误", "warning", JOptionPane.WARNING_MESSAGE);
			e.printStackTrace();
		}
		char[] Passwordc = SELF.REPASSWORDJPF.getPassword();
		StringBuilder Passwordb = new StringBuilder("");
		for (char i : Passwordc) {
			Passwordb.append(i);
		}
		String Password = Passwordb.toString();
		String com = "";
		if(SELF.getJMenuBar()==SELF.MANAGEMENUBAR)
			com = "MANAGE";
		else
			com = "USER";
		String[] args = {SELF.REUSERNAMEJTF.getText(),Password,com};
		SQLServer.additem("user", args);
		JOptionPane.showMessageDialog(SELF, "注册成功!", "warning", JOptionPane.WARNING_MESSAGE);
	}
	
	public void actionlogout( ) {
		SELF.getContentPane().removeAll();
		SELF.setJMenuBar(null);
		SELF.add(SELF.LOGINJP);
		SELF.add(SELF.BACKGROUNDJP);
		SELF.revalidate();
	}
	
	public void actionshowstock() {
		SELF.getContentPane().removeAll();
		SELF.StockJSP.updateUI();
		SELF.add(SELF.StockJSP);
		SELF.repaint();
	}
	
	public void actionshowsale() {
		SELF.getContentPane().removeAll();
		SELF.SaleJSP.updateUI();
		SELF.add(SELF.SaleJSP);
		SELF.repaint();
	}
	
	public void actionsearchstock() {
		SELF.getContentPane().removeAll();
		SELF.add(SELF.SEARCHSTOCKJP);
		SELF.add(SELF.BACKGROUNDJP);
		SELF.repaint();
	}
	
	public void actionstockin() {
		SELF.getContentPane().removeAll();
		SELF.add(SELF.STOCKINJP);
		SELF.add(SELF.BACKGROUNDJP);
		SELF.repaint();
	}
	
	public void searchstock() {
		if(SELF.SEARCHSTOCKJTF.getText().equals(""))
			JOptionPane.showMessageDialog(SELF, "请填写筛选条件", "warning", JOptionPane.WARNING_MESSAGE);
		SELF.SEARCHSTOCKJT = new JTable(new SaleTableModel(SELF, "stock",(String) SELF.SEARCHSTOCKJCB.getSelectedItem(), SELF.SEARCHSTOCKJTF.getText()));
		SELF.SearchStockJSP = new JScrollPane(SELF.SEARCHSTOCKJT);
		SELF.getContentPane().removeAll();
		SELF.SearchStockJSP.setBounds(0, 0,1188,648);
		SELF.add(SELF.SearchStockJSP);
		SELF.repaint();
	}
	
	public void actionsearchsale() {
		SELF.getContentPane().removeAll();
		SELF.add(SELF.SEARCHSALEJP);
		SELF.add(SELF.BACKGROUNDJP);
		SELF.repaint();
	}
	
	public void searchsale() {
		if(SELF.SEARCHSALEJTF.getText().equals(""))
			JOptionPane.showMessageDialog(SELF, "请填写筛选条件", "warning", JOptionPane.WARNING_MESSAGE);
		SELF.SEARCHSALEJT = new JTable(new SaleTableModel(SELF,"sale",(String) SELF.SEARCHSALEJCB.getSelectedItem(),SELF.SEARCHSALEJTF.getText()));
		SELF.SearchSaleJSP = new JScrollPane(SELF.SEARCHSALEJT);
		SELF.getContentPane().removeAll();
		SELF.SearchSaleJSP.setBounds(0, 0,1188,648);
		SELF.add(SELF.SearchSaleJSP);
		SELF.repaint();
	} 
	
	public void actionstockout() {
		boolean flag = true;
		int jsp = 0;
		for(java.awt.Component i:SELF.getRootPane().getContentPane().getComponents()) {
			if(i == SELF.StockJSP) {
				flag = false;
				jsp = 1;
			}
			if(i == SELF.SearchStockJSP) {
				flag = false;
				jsp = 2;
			}
		}
		if(flag||(jsp == 1 && SELF.ShowStockJT.getSelectedRow() == -1)||(jsp == 2 && SELF.SEARCHSTOCKJT.getSelectedRow() == -1)) {
			JOptionPane.showMessageDialog(SELF, "请在SearchStock或ShowStock选中项之后使用此功能", "warning", JOptionPane.WARNING_MESSAGE);
			return;
		}
		Date date = new Date();
		SimpleDateFormat dataformat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		if(jsp == 1) {
			String[] args = {dataformat.format(date),(String) SELF.ShowStockJT.getValueAt(SELF.ShowStockJT.getSelectedRow(), 1),(String) SELF.ShowStockJT.getValueAt(SELF.ShowStockJT.getSelectedRow(), 2),(String) SELF.ShowStockJT.getValueAt(SELF.ShowStockJT.getSelectedRow(), 3),(String) SELF.ShowStockJT.getValueAt(SELF.ShowStockJT.getSelectedRow(), 4),(String) SELF.ShowStockJT.getValueAt(SELF.ShowStockJT.getSelectedRow(), 5),(String) SELF.ShowStockJT.getValueAt(SELF.ShowStockJT.getSelectedRow(), 6),(String) SELF.ShowStockJT.getValueAt(SELF.ShowStockJT.getSelectedRow(), 7)};
			SQLServer.additem("sale",args);
			SQLServer.deleteitem("stock","time",(String) SELF.ShowStockJT.getValueAt(SELF.ShowStockJT.getSelectedRow(), 0));
			SELF.StockJSP.updateUI();
		}
		else if(jsp == 2) {
			String[] args = {dataformat.format(date),(String) SELF.SEARCHSTOCKJT.getValueAt(SELF.SEARCHSTOCKJT.getSelectedRow(), 1),(String) SELF.SEARCHSTOCKJT.getValueAt(SELF.SEARCHSTOCKJT.getSelectedRow(), 2),(String) SELF.SEARCHSTOCKJT.getValueAt(SELF.SEARCHSTOCKJT.getSelectedRow(), 3),(String) SELF.SEARCHSTOCKJT.getValueAt(SELF.SEARCHSTOCKJT.getSelectedRow(), 4),(String) SELF.SEARCHSTOCKJT.getValueAt(SELF.SEARCHSTOCKJT.getSelectedRow(), 5),(String) SELF.SEARCHSTOCKJT.getValueAt(SELF.ShowStockJT.getSelectedRow(), 6),(String) SELF.SEARCHSTOCKJT.getValueAt(SELF.SEARCHSTOCKJT.getSelectedRow(), 7)};
			SQLServer.additem("sale",args);
			SQLServer.deleteitem("stock","time",(String) SELF.SEARCHSTOCKJT.getValueAt(SELF.SEARCHSTOCKJT.getSelectedRow(), 0));
			SELF.SEARCHSTOCKJT.updateUI();
		}
		SELF.repaint();
	}
	
	public void actionsaleout() {
		boolean flag = true;
		int jsp = 0;
		for(java.awt.Component i:SELF.getRootPane().getContentPane().getComponents()) {
			if(i == SELF.SaleJSP) {
				flag = false;
				jsp = 1;
			}
			if(i == SELF.SearchSaleJSP) {
				flag = false;
				jsp = 2;
			}
		}
		if(flag||(jsp == 1&&SELF.ShowSaleJT.getSelectedRow() == -1)||(jsp ==2 &&SELF.SEARCHSALEJT.getSelectedRow() == -1)) {
			JOptionPane.showMessageDialog(SELF, "请在SearchSale或ShowSale选中项之后使用此功能", "warning", JOptionPane.WARNING_MESSAGE);
			return;
		}
		if(jsp == 1) {
			SQLServer.deleteitem("sale","time",(String) SELF.ShowSaleJT.getValueAt(SELF.ShowSaleJT.getSelectedRow(), 0));
			SELF.StockJSP.updateUI();
		}
		else if(jsp == 2) {
			SQLServer.deleteitem("sale","time",(String) SELF.SEARCHSALEJT.getValueAt(SELF.SEARCHSALEJT.getSelectedRow(), 0));
			SELF.SEARCHSTOCKJT.updateUI();
		}
		SELF.repaint();
	}
	
	public void stockin() {
		Date date = new Date();
		SimpleDateFormat dataformat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		String[] args = {dataformat.format(date),SELF.NAMEJTF.getText(),SELF.RESTJTF.getText(),SELF.SHAPEJTF.getText(),SELF.COLORJTF.getText(),SELF.CLOSEWAYJTF.getText(),SELF.MATERIALJTF.getText(),SELF.SIZEJTF.getText()};
		for(String i:args) {
			if(i.equals("")) {
				JOptionPane.showMessageDialog(SELF, "请完善信息", "warning", JOptionPane.WARNING_MESSAGE);
				return;
			}
		}
		SQLServer.additem("stock", args);
		JOptionPane.showMessageDialog(SELF, "添加成功!", "warning", JOptionPane.WARNING_MESSAGE);
	}
}
