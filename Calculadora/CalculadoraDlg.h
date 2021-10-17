
// CalculadoraDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CCalculadoraDlg
class CCalculadoraDlg : public CDialogEx
{
// Construcción
public:
	CCalculadoraDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULADORA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedEntreButton();
	afx_msg void OnBnClicked0Button();
	afx_msg void OnBnClicked1Button();
	afx_msg void OnBnClicked2Button2();
	afx_msg void OnBnClicked2Button();
	afx_msg void OnBnClicked3Button();
	afx_msg void OnBnClicked4Button();
	afx_msg void OnBnClicked5Button();
	afx_msg void OnBnClicked6Button();
	afx_msg void OnBnClicked7Button();
	afx_msg void OnBnClicked8Button();
	afx_msg void OnBnClicked9Button();
	CString m_resultado;
	int m_resultado_entero;
	CString m_base;
	afx_msg void OnBnClickedMasButton();
	afx_msg void OnBnClickedMenosButton();
	afx_msg void OnBnClickedPorButton();
	afx_msg void OnBnClickedDivButton();
	afx_msg void OnBnClickedIgualButton();
	afx_msg void OnBnClickedCeButton();
	afx_msg void OnStnClickedStaticBin();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnCbnSelchangeBaseCombo();
	afx_msg void OnBnClickedBaseButton();
	CString m_Bin;
	afx_msg void OnEnChangeResultEdit();
	afx_msg void OnBnClickedCheck2();
	int m_Bin_entero;
	afx_msg void OnStnClickedStaticBinE();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedBaseclearButton();
};
