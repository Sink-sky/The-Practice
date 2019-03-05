package com.sinksky;

import java.awt.*;
import javax.swing.*;


@SuppressWarnings("serial")
public class SaleFrame extends JFrame{
	//将需要的组件全部放在JFame中
	//组成一个JFrame环境
	//事件响应进程只需在此环境中修改获取参数即可
	
	//侧边栏
	JMenuBar MANAGEMENUBAR = new JMenuBar();
	JMenuBar USERMENUBAR = new JMenuBar();
	
	//一级菜单
	JMenu HOME = new JMenu("Home");
	JMenu USER = new JMenu("User");
	JMenu STOCK = new JMenu("Stock");
	JMenu SALE = new JMenu("Sale");
//	JMenu LOG = new JMenu("Log");
	JMenu JHOME = new JMenu("Home");
	JMenu JUSER = new JMenu("User");
	JMenu JSTOCK = new JMenu("Stock");
	JMenu JSALE = new JMenu("Sale");
	
	//二级菜单
	JMenuItem REGISTER = new JMenuItem("Register");
	JMenuItem LOGOUT = new JMenuItem("Logout");
		
	JMenuItem SHOWSTOCK = new JMenuItem("Showstock");
	JMenuItem SEARCHSTOCK = new JMenuItem("Searchstock");
//	JMenuItem EXPORTSTOCK = new JMenuItem("Exportstock");
//	JMenuItem IMPORTSTOCK = new JMenuItem("Importstock");
	
	JMenuItem SHOWSALE = new JMenuItem("Showsale");	
	JMenuItem SEARCHSALE = new JMenuItem("Searchsale");
//	JMenuItem EXPORTSALE = new JMenuItem("Exportsale");
//	JMenuItem IMPORTSALE = new JMenuItem("Importsale");
	
//	JMenuItem SHOWLOG = new JMenuItem("Showlog");
//	JMenuItem SEARCHLOG = new JMenuItem("Searchlog");
//	JMenuItem DELETELOG = new JMenuItem("Deletelog");
	JMenuItem JREGISTER = new JMenuItem("Register");
	JMenuItem JLOGOUT = new JMenuItem("Logout");
		
	JMenuItem JSHOWSTOCK = new JMenuItem("Showstock");
	JMenuItem JSEARCHSTOCK = new JMenuItem("Searchstock");
	JMenuItem JSTOCKIN = new JMenuItem("Stockin");
	JMenuItem JSTOCKOUT = new JMenuItem("Stockout");
	
	JMenuItem JSHOWSALE = new JMenuItem("Showsale");	
	JMenuItem JSEARCHSALE = new JMenuItem("Searchsale");
	JMenuItem JSALEOUT = new JMenuItem("Saleout");
	
	//图片背景
	JPanel BACKGROUNDJP = new JPanel();
	
	//登陆
	JPanel LOGINJP = new JPanel();
	JButton LOGINJB = new JButton("登入");
	
	JLabel WELCOMEJL = new JLabel("欢迎来到销售信息系统");
	JLabel USERNAMEJL = new JLabel("用户名");
	JLabel PASSWORDJL = new JLabel("密码");
	JTextField USERNAMEJTF = new JTextField("");
	JPasswordField PASSWORDJPF = new JPasswordField("");
	
	//注册
	@SuppressWarnings({ "unchecked", "rawtypes" })
	JComboBox COMPETENCEJCB = new JComboBox(new String[] {"管理员","游客"});
	JPanel REGISTERJP = new JPanel();
	JLabel COMPETENCEJL = new JLabel("权限");
	JLabel REUSERNAMEJL = new JLabel("用户名");
	JLabel REPASSWORDJL = new JLabel("密码");
	JTextField REUSERNAMEJTF = new JTextField("");
	JPasswordField REPASSWORDJPF = new JPasswordField("");
	JButton REGISTERJB = new JButton("注册");
	
	
	//Stockin
	JPanel STOCKINJP = new JPanel();
	JLabel STOCKINJL = new JLabel("STOCKIN");
	JLabel NAMEJL = new JLabel("名称");
	JLabel RESTJL = new JLabel("数量");
	JLabel SHAPEJL = new JLabel("形状");
	JLabel COLORJL = new JLabel("颜色");
	JLabel CLOSEWAYJL = new JLabel("闭合方式");
	JLabel MATERIALJL = new JLabel("材质");
	JLabel SIZEJL = new JLabel("大小");
	JTextField NAMEJTF = new JTextField("");
	JTextField RESTJTF = new JTextField("");
	JTextField SHAPEJTF = new JTextField("");
	JTextField COLORJTF = new JTextField("");
	JTextField CLOSEWAYJTF = new JTextField("");
	JTextField MATERIALJTF = new JTextField("");
	JTextField SIZEJTF = new JTextField("");
	JButton STOCKINJB = new JButton("入库");
	
	//SearchStock JPanel
	JPanel SEARCHSTOCKJP = new JPanel();
	@SuppressWarnings({ "unchecked", "rawtypes" })
	JComboBox SEARCHSTOCKJCB = new JComboBox(new String[] {"name","rest","shape","color","closeway","material","size"});
	JButton SEARCHSTOCKJB = new JButton("SEARCHSTOCK");
	JTextField SEARCHSTOCKJTF = new JTextField();
	JTable SEARCHSTOCKJT;
	JScrollPane SearchStockJSP;
	
	//SearchSale Jpanel
	JPanel SEARCHSALEJP = new JPanel();
	@SuppressWarnings({ "rawtypes", "unchecked" })
	JComboBox SEARCHSALEJCB = new JComboBox(new String[] {"name","price","num","shape","color","closeway","material","size"});
	JButton SEARCHSALEJB = new JButton("SEARCHSALE");
	JTextField SEARCHSALEJTF = new JTextField();
	JTable SEARCHSALEJT;
	JScrollPane SearchSaleJSP;
	//选中出库出售
	
	//Showstock
	JTable ShowStockJT = new JTable(new SaleTableModel(this, "stock"));
	JScrollPane StockJSP = new JScrollPane(ShowStockJT);
	
	//Showsale
	JTable ShowSaleJT = new JTable(new SaleTableModel(this, "sale"));
	JScrollPane SaleJSP = new JScrollPane(ShowSaleJT);
	
	//默认构造函数(做必要的init)
	public SaleFrame() {
		super("靓丽皮包销售信息系统");
		
		//观感
		try {
			UIManager.setLookAndFeel( "com.sun.java.swing.plaf.windows.WindowsClassicLookAndFeel" );
		} catch (ClassNotFoundException | InstantiationException | IllegalAccessException
				| UnsupportedLookAndFeelException e) {
			e.printStackTrace();
			JOptionPane.showMessageDialog(this, "初始化失败,请检查运行环境", "warning", JOptionPane.WARNING_MESSAGE);
		}
		SwingUtilities.updateComponentTreeUI(SaleFrame.this);
		
		//图标
		ImageIcon ICON = new ImageIcon("Image/Cup.png");
		this.setIconImage(ICON.getImage());
		
		//布局and大小and位置
		this.setSize(1188,648);
		this.setLayout(null);
		this.setResizable(false);
		Dimension screensize = Toolkit.getDefaultToolkit().getScreenSize();
		Dimension framesize = this.getSize();
		int framewidth = (int) framesize.getWidth();
		int frameheight = (int) framesize.getHeight();
		int x = (int) screensize.getWidth() / 2 - framewidth / 2;
		int y = (int) screensize.getHeight() / 2 - frameheight / 2;
		this.setLocation(x,y);
		
		//加载组件(先添加的在最前面)
		this.loadmembar();
		this.loadlogin();
		this.loadregister();
		this.loadbackground();
		this.loadstockin();
		this.loadsearchsale();
		this.loadsearchstock();
		
		//各种Jpanel的初始化
		
		SaleJSP.setBounds(0, 0,framewidth, frameheight);
		StockJSP.setBounds(0,0,framewidth, frameheight);
		
		LOGINJP.setBounds(0, 0, framewidth, frameheight);
		this.add(LOGINJP);
//		LOGINJP.setVisible(false);
		
		REGISTERJP.setBounds(0, 0, framewidth, frameheight);
//		this.add(REGISTERJP);
//		REGISTERJP.setVisible(false);
		
		STOCKINJP.setBounds(0, 0, framewidth,frameheight);
//		this.add(STOCKINJP);
//		STOCKINJP.setVisible(false);
		
		BACKGROUNDJP.setBounds(0, 0, framewidth,frameheight);
		this.add(BACKGROUNDJP);
//		BACKGROUNDJP.setVisible(false);
//		this.getContentPane().removeAll();
		
		SEARCHSALEJP.setBounds(0, 0, framewidth,frameheight);
		
		SEARCHSTOCKJP.setBounds(0, 0, framewidth,frameheight);
	}
	
	void loadbackground() {
		Icon WELCOME = new ImageIcon("Image/Welcome.jpg");
		JLabel BACKGROUND = new JLabel();
		BACKGROUND.setIcon(WELCOME);
		BACKGROUND.setOpaque(false);
		BACKGROUND.setBounds(0,0,1188,648);
		BACKGROUNDJP.add(BACKGROUND);
	}
	
	void loadmembar() {
		USER.add(REGISTER);
		USER.add(LOGOUT);
		REGISTER.addActionListener(new SaleEvent(this));
		LOGOUT.addActionListener(new SaleEvent(this));
		STOCK.add(SHOWSTOCK);
		STOCK.add(SEARCHSTOCK);
		SHOWSTOCK.addActionListener(new SaleEvent(this));
		SEARCHSTOCK.addActionListener(new SaleEvent(this));
		SALE.add(SHOWSALE);
		SALE.add(SEARCHSALE);
		SHOWSALE.addActionListener(new SaleEvent(this));
		SEARCHSALE.addActionListener(new SaleEvent(this));
		USERMENUBAR.add(HOME);
		USERMENUBAR.add(USER);
		USERMENUBAR.add(STOCK);
		USERMENUBAR.add(SALE);
		
		JUSER.add(JREGISTER);
		JUSER.add(JLOGOUT);
		JSTOCK.add(JSHOWSTOCK);
		JSTOCK.add(JSEARCHSTOCK);
		JSALE.add(JSHOWSALE);
		JSALE.add(JSEARCHSALE);
		JREGISTER.addActionListener(new SaleEvent(this));
		JLOGOUT.addActionListener(new SaleEvent(this));
		JSHOWSTOCK.addActionListener(new SaleEvent(this));
		JSEARCHSTOCK.addActionListener(new SaleEvent(this));
		JSHOWSALE.addActionListener(new SaleEvent(this));
		JSEARCHSALE.addActionListener(new SaleEvent(this));
		
		JSTOCK.addSeparator();
		JSTOCK.add(JSTOCKIN);
		JSTOCK.add(JSTOCKOUT);
		JSTOCKIN.addActionListener(new SaleEvent(this));
		JSTOCKOUT.addActionListener(new SaleEvent(this));
		JSALE.addSeparator();
		JSALE.add(JSALEOUT);
		JSALEOUT.addActionListener(new SaleEvent(this));
//		LOG.add(SHOWLOG);
//		LOG.add(SEARCHLOG);
//		LOG.addSeparator();
//		LOG.add(DELETELOG);
		MANAGEMENUBAR.add(JHOME);
		MANAGEMENUBAR.add(JUSER);
		MANAGEMENUBAR.add(JSTOCK);
		MANAGEMENUBAR.add(JSALE);
//		MANAGEMENUBAR.add(LOG);
	}
	
	void loadlogin() {
		LOGINJP.setOpaque(false);
		LOGINJP.setLayout(null);
		WELCOMEJL.setFont(new Font("Dialog", 1, 30));
		USERNAMEJL.setFont(new Font("Dialog", 1, 20));
		PASSWORDJL.setFont(new Font("Dialog", 1, 20));
		WELCOMEJL.setBounds(434,139,320,30);
		USERNAMEJL.setBounds(393,209,66,22);
		PASSWORDJL.setBounds(404,259,44,22);
		USERNAMEJTF.setPreferredSize(new Dimension(310, 30));
		PASSWORDJPF.setPreferredSize(new Dimension(310, 30));
		USERNAMEJTF.setBounds(470,204,310,32);
		PASSWORDJPF.setBounds(470,254,310,32);
		LOGINJB.setBounds(540,304,100,32);
		LOGINJB.addActionListener(new SaleEvent(this));
		LOGINJP.add(WELCOMEJL);
		LOGINJP.add(USERNAMEJL);
		LOGINJP.add(USERNAMEJTF);
		LOGINJP.add(PASSWORDJL);
		LOGINJP.add(PASSWORDJPF);
		LOGINJP.add(LOGINJB);
	}
	
	void loadregister() {
		REGISTERJP.setOpaque(false);
		REGISTERJP.setLayout(null);
		COMPETENCEJL.setFont(new Font("Dialog", 1, 20));
		REUSERNAMEJL.setFont(new Font("Dialog", 1, 20));
		REPASSWORDJL.setFont(new Font("Dialog", 1, 20));
		REUSERNAMEJL.setBounds(393,209,66,22);
		REPASSWORDJL.setBounds(404,259,44,22);
		REUSERNAMEJTF.setPreferredSize(new Dimension(310, 30));
		REPASSWORDJPF.setPreferredSize(new Dimension(310, 30));
		REUSERNAMEJTF.setBounds(470,204,310,32);
		REPASSWORDJPF.setBounds(470,254,310,32);
		COMPETENCEJL.setBounds(404,159,66,22);
		COMPETENCEJCB.setBounds(470,154,100,30);
		REGISTERJB.setBounds(540,304,100,32);
		REGISTERJB.addActionListener(new SaleEvent(this));
		REGISTERJP.add(COMPETENCEJL);
		REGISTERJP.add(COMPETENCEJCB);
		REGISTERJP.add(REUSERNAMEJL);
		REGISTERJP.add(REUSERNAMEJTF);
		REGISTERJP.add(REPASSWORDJL);
		REGISTERJP.add(REPASSWORDJPF);
		REGISTERJP.add(REGISTERJB);
	}
	
	void loadstockin() {
		STOCKINJP.setOpaque(false);
		STOCKINJP.setLayout(null);
		STOCKINJL.setFont(new Font("Dialog", 1, 30));
		NAMEJL.setFont(new Font("Dialog", 1, 20));
		RESTJL.setFont(new Font("Dialog", 1, 20));
		SHAPEJL.setFont(new Font("Dialog", 1, 20));
		COLORJL.setFont(new Font("Dialog", 1, 20));
		CLOSEWAYJL.setFont(new Font("Dialog", 1, 20));
		MATERIALJL.setFont(new Font("Dialog", 1, 20));
		SIZEJL.setFont(new Font("Dialog", 1, 20));
		STOCKINJL.setBounds(534,30,320,30);
		NAMEJL.setBounds(393,100,44,20);
		RESTJL.setBounds(393,150,44,20);
		SHAPEJL.setBounds(393,200,44,20);
		COLORJL.setBounds(393,250,44,20);
		CLOSEWAYJL.setBounds(353,300,88,20);
		MATERIALJL.setBounds(393,350,44,20);
		SIZEJL.setBounds(393,400,44,20);
		NAMEJTF.setPreferredSize(new Dimension(310, 30));
		RESTJTF.setPreferredSize(new Dimension(310, 30));
		SHAPEJTF.setPreferredSize(new Dimension(310, 30));
		COLORJTF.setPreferredSize(new Dimension(310, 30));
		CLOSEWAYJTF.setPreferredSize(new Dimension(310, 30));
		MATERIALJTF.setPreferredSize(new Dimension(310, 30));
		SIZEJTF.setPreferredSize(new Dimension(310, 30));
		NAMEJTF.setBounds(470,94,310,32);
		RESTJTF.setBounds(470,144,310,32);
		SHAPEJTF.setBounds(470,194,310,32);
		COLORJTF.setBounds(470,244,310,32);
		CLOSEWAYJTF.setBounds(470,294,310,32);
		MATERIALJTF.setBounds(470,344,310,32);
		SIZEJTF.setBounds(470,394,310,32);
		STOCKINJB.setBounds(540,444,100,32);
		STOCKINJB.addActionListener(new SaleEvent(this));
		STOCKINJP.add(STOCKINJL);
		STOCKINJP.add(NAMEJL);
		STOCKINJP.add(RESTJL);
		STOCKINJP.add(SHAPEJL);
		STOCKINJP.add(COLORJL);
		STOCKINJP.add(CLOSEWAYJL);
		STOCKINJP.add(MATERIALJL);
		STOCKINJP.add(SIZEJL);
		STOCKINJP.add(NAMEJTF);
		STOCKINJP.add(RESTJTF);
		STOCKINJP.add(SHAPEJTF);
		STOCKINJP.add(COLORJTF);
		STOCKINJP.add(CLOSEWAYJTF);
		STOCKINJP.add(MATERIALJTF);
		STOCKINJP.add(SIZEJTF);
		STOCKINJP.add(STOCKINJB);
	}
	
	void loadsearchstock() {
		SEARCHSTOCKJP.setOpaque(false);
		SEARCHSTOCKJP.setLayout(null);
		SEARCHSTOCKJB.setPreferredSize(new Dimension(310, 30));
		SEARCHSTOCKJCB.setBounds(470,154,100,30);
		SEARCHSTOCKJTF.setBounds(470,204,310,32);
		SEARCHSTOCKJB.setBounds(500,254,200,32);
		SEARCHSTOCKJP.add(SEARCHSTOCKJCB);
		SEARCHSTOCKJP.add(SEARCHSTOCKJTF);
		SEARCHSTOCKJP.add(SEARCHSTOCKJB);
		SEARCHSTOCKJB.addActionListener(new SaleEvent(this));
	}
	
	void loadsearchsale() {
		SEARCHSALEJP.setOpaque(false);
		SEARCHSALEJP.setLayout(null);
		SEARCHSALEJB.setPreferredSize(new Dimension(310, 30));
		SEARCHSALEJCB.setBounds(470,154,100,30);
		SEARCHSALEJTF.setBounds(470,204,310,32);
		SEARCHSALEJB.setBounds(500,254,200,32);
		SEARCHSALEJP.add(SEARCHSALEJCB);
		SEARCHSALEJP.add(SEARCHSALEJTF);
		SEARCHSALEJP.add(SEARCHSALEJB);
		SEARCHSALEJB.addActionListener(new SaleEvent(this));
	}
}



