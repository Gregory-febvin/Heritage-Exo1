#include <stdio.h>
#include <stdlib.h>
#include "dd.h"
#include "HritageExo1.h"
#include <qDebug>
#include "DeHisto.h"

HritageExo1::HritageExo1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	de = new dd();

	DeNormal();
}

void HritageExo1::DeHisto()
{
	ui.pushButton_3->setVisible(true);
	ui.tableWidget->setVisible(true);
	ui.NbDe->setVisible(true);
	ui.label_3->setVisible(true);

	ui.label->setVisible(false);
	ui.label_2->setVisible(false);
	ui.pushButton->setVisible(false);
	ui.pushButton_2->setVisible(false);
	ui.pushButton_4->setVisible(false);
}

void HritageExo1::DeNormal()
{
	ui.label->setVisible(true);
	ui.label_2->setVisible(true);
	ui.pushButton->setVisible(true);
	ui.pushButton_2->setVisible(true);
	ui.pushButton_4->setVisible(true);

	ui.pushButton_3->setVisible(false);
	ui.tableWidget->setVisible(false);
	ui.NbDe->setVisible(false);
	ui.label_3->setVisible(false);
}

void HritageExo1::LanceDe()
{
	
	(*de)++;
	
	HritageExo1::AfficheValeurDe();

	this->n += (*de);
	qDebug() << this->n;

	this->n < (*de);
}

void HritageExo1::AfficheValeurDe()
{
	this->n += (*de);

	QString Score = QString::number(this->n);
	ui.label_2->setText(Score);
	
}

void HritageExo1::RemiseScoreZero()
{
	
	(*de)=(0);

}

void HritageExo1::AfficheScore()
{
	
	this->n < (*de);

	QString ScoreTotal = QString::number(this->n);
	ui.label->setText(ScoreTotal);
	
}

void HritageExo1::DeMultiple()
{
	QString NbDe = ui.NbDe->text();
	int NbLancer = NbDe.toInt();

	if( NbLancer < 8 )
	{
		if (NbLancer == 1)
		{
			this->deMultiple->jet();
		}
		else {
			this->deMultiple->jet(NbLancer);
		}
		
	} else {
		qDebug() << "Mon programme de mort ne peut lancer que 7 de a la fois";
	}
	
	ui.tableWidget->setRowCount(7);

	for (int i = 0; i < NbLancer; i++)
	{
		int tableau = deMultiple->getValeurTableau(i);
			
		ui.tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(tableau)));
	}
}