/*
 * QFileViewController.h
 *
 *  Created on: 18 juil. 2018
 *      Author: ebeuque
 */

#ifndef SRC_GUICONTROLLER_QFILEVIEWCONTROLLER_H_
#define SRC_GUICONTROLLER_QFILEVIEWCONTROLLER_H_

#include <QString>
#include <QFile>

class QFileView;

class QFileViewController
{
public:
	QFileViewController(QFileView* pFileView);
	virtual ~QFileViewController();

	bool openFile(const QString& szFilePath);
	void closeFile();

private:
	QFileView* m_pFileView;

	// Current file
	bool m_bIsFileOpen;
	QFile m_file;
	qint64 m_iFileSize;
	qint64 m_iFilePos;

	// Current display
	int m_iBytePerLine;
	int m_iTotalRowCount;
	int m_iVisibleRowCount;

	bool readFile(qint64 iStartOffset);
};

#endif /* SRC_GUICONTROLLER_QFILEVIEWCONTROLLER_H_ */