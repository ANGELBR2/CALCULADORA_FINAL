
// CalculadoraDlg.cpp: archivo de implementación
//

#include <iostream>
#include "pch.h"
#include "framework.h"
#include "Calculadora.h"
#include "CalculadoraDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

using namespace std;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CCalculadoraDlg



CCalculadoraDlg::CCalculadoraDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_CALCULADORA_DIALOG, pParent)
	//, m_result(_T(""))
	, m_resultado(_T(""))
	, m_resultado_entero(0)
	, m_base(_T(""))
	, m_Bin(_T(""))
	, m_Bin_entero(0)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculadoraDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_tex_EDIT, m_result);
	DDX_Text(pDX, IDC_RESULT_EDIT, m_resultado);
	DDX_Text(pDX, IDC_RESULT_STATIC, m_resultado_entero);
	DDX_Text(pDX, IDC_STATIC_BIN, m_Bin);
}

BEGIN_MESSAGE_MAP(CCalculadoraDlg, CDialogEx)   // se agregan los botones que son utilizados 
	ON_WM_SYSCOMMAND()					    	// en toda la programacion de la calculadora
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0_BUTTON, &CCalculadoraDlg::OnBnClicked0Button)
	ON_BN_CLICKED(IDC_1_BUTTON, &CCalculadoraDlg::OnBnClicked1Button)
	ON_BN_CLICKED(IDC_2_BUTTON, &CCalculadoraDlg::OnBnClicked2Button)
	ON_BN_CLICKED(IDC_3_BUTTON, &CCalculadoraDlg::OnBnClicked3Button)
	ON_BN_CLICKED(IDC_4_BUTTON, &CCalculadoraDlg::OnBnClicked4Button)
	ON_BN_CLICKED(IDC_5_BUTTON, &CCalculadoraDlg::OnBnClicked5Button)
	ON_BN_CLICKED(IDC_6_BUTTON, &CCalculadoraDlg::OnBnClicked6Button)
	ON_BN_CLICKED(IDC_7_BUTTON, &CCalculadoraDlg::OnBnClicked7Button)
	ON_BN_CLICKED(IDC_8_BUTTON, &CCalculadoraDlg::OnBnClicked8Button)
	ON_BN_CLICKED(IDC_9_BUTTON, &CCalculadoraDlg::OnBnClicked9Button)
	ON_BN_CLICKED(IDC_MAS_BUTTON, &CCalculadoraDlg::OnBnClickedMasButton)
	ON_BN_CLICKED(IDC_MENOS_BUTTON, &CCalculadoraDlg::OnBnClickedMenosButton)
	ON_BN_CLICKED(IDC_POR_BUTTON, &CCalculadoraDlg::OnBnClickedPorButton)
	ON_BN_CLICKED(IDC_DIV_BUTTON, &CCalculadoraDlg::OnBnClickedDivButton)
	ON_BN_CLICKED(IDC_IGUAL_BUTTON, &CCalculadoraDlg::OnBnClickedIgualButton)
	ON_BN_CLICKED(IDC_CE_BUTTON, &CCalculadoraDlg::OnBnClickedCeButton)
	ON_BN_CLICKED(IDC_CHECK1, &CCalculadoraDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK3, &CCalculadoraDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_BASECLEAR_BUTTON, &CCalculadoraDlg::OnBnClickedBaseclearButton)
END_MESSAGE_MAP()


// Controladores de mensajes de CCalculadoraDlg

BOOL CCalculadoraDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CCalculadoraDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CCalculadoraDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CCalculadoraDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Empezamos la programación del sistema 

int conteo, op1, op2;
int codigo_de_operacion;
int op1add;
int op2add;
int resultadoadd;
int resultadobin;


void CCalculadoraDlg::OnBnClicked0Button()
{
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "0";
		m_resultado_entero = 0;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked1Button()
{
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "1";
		m_resultado_entero = 1;
		op1 = m_resultado_entero;

		UpdateData(FALSE);
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 1;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked2Button()
{
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "2";
		m_resultado_entero = 2;
		op1 = m_resultado_entero;

		UpdateData(FALSE);
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 2;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked3Button()
{
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "3";
		m_resultado_entero = 3;
		op1 = m_resultado_entero;
		UpdateData(FALSE);
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 3;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked4Button()
{
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "4";
		m_resultado_entero = 4;
		op1 = m_resultado_entero;
		UpdateData(FALSE);
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 4;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked5Button()
{
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "5";
		m_resultado_entero = 5;
		op1 = m_resultado_entero;
		UpdateData(FALSE);
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 5;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked6Button()
{
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "6";
		m_resultado_entero = 6;
		op1 = m_resultado_entero;
		UpdateData(FALSE);
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 6;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked7Button()
{
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "7";
		m_resultado_entero = 7;
		op1 = m_resultado_entero;
		UpdateData(FALSE);
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 7;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked8Button()
{

	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "8";
		m_resultado_entero = 8;
		op1 = m_resultado_entero;
		UpdateData(FALSE);
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 8;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked9Button()
{
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "9";
		m_resultado_entero = 9;
		op1 = m_resultado_entero;
		UpdateData(FALSE);
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2 + 9;
		m_resultado_entero = op1;
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}

// iniciamos la programación de las operaciones 
void CCalculadoraDlg::OnBnClickedMasButton()
{
	codigo_de_operacion = 1;
	op1add = op1;
	op2add = op2;
	resultadoadd = m_resultado_entero;

	conteo = 0;

	CString MyCadenita;
	MyCadenita.Format(L"%d +", resultadoadd);
	m_resultado = MyCadenita;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClickedMenosButton()
{
	codigo_de_operacion = 2;
	op1add = op1;
	op2add = op2;
	resultadoadd = m_resultado_entero;

	conteo = 0;
	CString MyCadenita;
	MyCadenita.Format(L"%d -", resultadoadd);
	m_resultado = MyCadenita;
	UpdateData(FALSE);
}



void CCalculadoraDlg::OnBnClickedPorButton()
{
	codigo_de_operacion = 3;
	op1add = op1;
	op2add = op2;
	resultadoadd = m_resultado_entero;

	conteo = 0;
	CString MyCadenita;
	MyCadenita.Format(L"%d x", resultadoadd);
	m_resultado = MyCadenita;
	UpdateData(FALSE);

}



void CCalculadoraDlg::OnBnClickedDivButton()
{
	codigo_de_operacion = 4;
	op1add = op1;
	op2add = op2;
	resultadoadd = m_resultado_entero;

	conteo = 0;
	CString MyCadenita;
	MyCadenita.Format(L"%d /", resultadoadd);
	m_resultado = MyCadenita;
	UpdateData(FALSE);
}


// programacion de la funcion =

void CCalculadoraDlg::OnBnClickedIgualButton()
{
	UpdateData(TRUE);
	switch (codigo_de_operacion)
	{
	case 1:
		m_resultado_entero = resultadoadd + op1;
		break;
	case 2:
		m_resultado_entero = resultadoadd - op1;
		break;
	case 3:
		m_resultado_entero = resultadoadd * op1;
		break;
	case 4:
		m_resultado_entero = resultadoadd / op1;
		break;
	default:
		break;
	}
	CString MyCadenita;
	MyCadenita.Format(L"= %d", m_resultado_entero);
	m_resultado = MyCadenita;
	UpdateData(FALSE);
}



//Programación de Cambio de Base 
//DECIMAL  a Binario

#include <iostream>


void CCalculadoraDlg::OnBnClickedCheck1()
{
	{
		int a[10], n, i; // i es el indicador de valores que se va a imprimir
		/// "actualizamos el numero a convertir ";
		UpdateData(TRUE);
		n = m_resultado_entero;
		for (i = 0; n > 0; i++)
		{
		a[i] = n % 2; // % para residuo de la division
		n = n / 2;
		}
		//limpiar cadena y generar ciclo para presentar dato convertido";
		m_Bin = "";
		UpdateData(FALSE);
		for (i = i - 1; i >= 0; i--)
		{

		m_Bin_entero = a[i];

		CString Cadena;
		Cadena.Format(L"%d", m_Bin_entero);	// L es el cambio de formato cadena a entero
		m_Bin += Cadena;
		}
		UpdateData(FALSE);
		}


}


void CCalculadoraDlg::OnBnClickedCheck3()
{

	UpdateData(TRUE);

	CString MyCadenita;
	MyCadenita.Format(L" % x", m_resultado_entero);
	m_Bin = MyCadenita;
	UpdateData(FALSE);

}

void CCalculadoraDlg::OnBnClickedCeButton()
{
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_entero = 0;
	resultadoadd = 0;
	m_Bin_entero = 0;
	resultadobin = 0;
	

	CString MyCadenita;
	MyCadenita.Format(L"= %d", m_resultado_entero);
	m_resultado = MyCadenita;
	UpdateData(FALSE);

}



void CCalculadoraDlg::OnBnClickedBaseclearButton()
{
	CString MyCadenita;
	MyCadenita.Format(L" % x", 0);
	m_Bin = MyCadenita;
	UpdateData(FALSE);
}

// Gracias