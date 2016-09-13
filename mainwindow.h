#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Item.h"
#include "qmap.h"

namespace Ui {
class MainWindow;
}


#define CHESS_ROWS		15
#define CHESS_COLUMES	15
#define RECT_WIDTH		50
#define RECT_HEIGHT		50

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
private:
	void DrawChessboard();
	void DrawItems();
	void DrawItemWithMouse();

	void DrawChessAtPoint(QPainter& painter,QPoint& pt);

	int CountNearItem(Item item,QPoint ptDirection);	//ͳ��ĳ������(��8������)�ϵ�������������QPoint��ʾͳ�Ʒ�����(1,1)��ʾ���·�,��-1,0����ʾ����
	//bool FindItem(Item item);
private:
    Ui::MainWindow *ui;

	QVector<Item> m_items;
	bool m_bIsBlackTurn;	//��ǰ�ú�����
};

#endif // MAINWINDOW_H
