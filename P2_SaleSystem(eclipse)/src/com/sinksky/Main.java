package com.sinksky;

import java.awt.event.*;

public class Main {	
	public static void main(String args[]) {
		//�����ݿ����
		SQLServer.open();
		SaleFrame SF = new SaleFrame();
		SF.addWindowListener(new WindowAdapter() {
			//�ر�ʱ����������
			public void windowClosing(WindowEvent windowEvent){
				SQLServer.close();
		        System.exit(0);
	         }   
		});
		SF.setVisible(true);
	}
}
