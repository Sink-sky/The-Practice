package com.sinksky;

import java.awt.event.*;

public class Main {	
	public static void main(String args[]) {
		//打开数据库服务
		SQLServer.open();
		SaleFrame SF = new SaleFrame();
		SF.addWindowListener(new WindowAdapter() {
			//关闭时该做的事情
			public void windowClosing(WindowEvent windowEvent){
				SQLServer.close();
		        System.exit(0);
	         }   
		});
		SF.setVisible(true);
	}
}
