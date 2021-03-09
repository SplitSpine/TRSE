#include "formttredit.h"
#include "ui_formttredit.h"

FormTTREdit::FormTTREdit(QWidget *parent) :
    TRSEDocument(parent),
    ui(new Ui::FormTTREdit)
{
    ui->setupUi(this);
    m_programEndingType = "ttr";
}

FormTTREdit::~FormTTREdit()
{
    delete ui;
}

void FormTTREdit::SaveCurrentInstrument()
{
    if (m_currentInstrument!=-1) {
        QByteArray ba;
        QStringList lst = ui->leInstrumentData->text().split(",");
        for (QString& s:lst)
            s = "$"+s;
        ba.append(Util::HexQStringListToByteArray(lst));
//        qDebug() << lst << ba;
//        ba.resize(11);
        QString txt = ui->leInstrument->text();
        int cur = 0;
        while (ba.count()<16) {
            if (cur<txt.length())
                ba.append(txt[cur].toLatin1());
            else
                ba.append((uchar)0);
            cur++;
        }
        m_ttr.m_instruments[m_currentInstrument] = ba;
    }

}

bool FormTTREdit::Load(QString filename) {
    m_ttr.Load(filename);
    m_rawFilename = filename;
    FillGUIFromData();
    ReloadPatterns();
    return true;
}

void FormTTREdit::Save(QString filename)
{
    ApplyCurrentOrder();
    m_ttr.Save(filename);

}

void FormTTREdit::Reload()
{
//    if (!ui->scrollArea->m_isChanged)
//        Load(m_rawFilename);
}

void FormTTREdit::InitDocument(WorkerThread *t, QSharedPointer<CIniFile> ini, QSharedPointer<CIniFile> iniProject) {
    TRSEDocument::InitDocument(t,ini,iniProject);
    //ui->scrollArea->m_doc = this;
    //ui->sc

    m_colors.Load(Util::GetSystemPrefix() + "themes/" + m_iniFile->getString("theme"));

}

void FormTTREdit::FillGUIFromData()
{
    ui->leText->setText(m_ttr.m_text);
    //ui->leInstruments->setText(Util::toString(Util::ByteArrayToHexQStringList(m_ttr.m_instruments)));
    //ui->leOrders->setText(Util::toString(Util::ByteArrayToHexQStringList(m_ttr.m_orders)));

    QComboBox* cmb = ui->cmbPattern;
    cmb->clear();
    for (int i=0;i<m_ttr.m_orders.count();i++) {
        cmb->addItem(QString::number(i));
    }

    cmb = ui->cmbInstruments;
    cmb->clear();
    for (int i=0;i<m_ttr.m_instruments.count();i++) {
        cmb->addItem(QString::number(i));
    }


    ReloadPatterns();

}

void FormTTREdit::ReloadPatterns()
{
    Util::clearLayout(ui->lyTrackers);
    m_curPatterns.clear();
    m_curPatternValues.clear();
    QVector<QByteArray> curPatt = m_ttr.getCurrentPattern();
    for (int i=0;i<curPatt.count();i++) {
        WidgetPattern* wp = new WidgetPattern();
        //ui->scrollArea->m_colors = &m_colors;
        m_curPatterns.append(wp);
        ui->lyTrackers->addWidget(wp);
        wp->SetData(this,&m_colors, QSharedPointer<DataStorageArray>(
                        new DataStorageArray(curPatt[i])));



        QComboBox* cmb = wp->getPatternCmb();
        cmb->clear();
        for (int i=0;i<m_ttr.m_patterns.count();i++)
            cmb->addItem(QString::number(i));

        cmb->setCurrentIndex((uchar)m_ttr.m_orders[m_ttr.m_currentOrder][i]);
        connect(wp, SIGNAL(emitReloadPatterns()), this, SLOT(UpdatePatterns()));
        m_curPatternValues.append((uchar)m_ttr.m_orders[m_ttr.m_currentOrder][i]);

    }
    //    ui->lyTrackers->re
}

void FormTTREdit::UpdatePatterns()
{
    ApplyCurrentOrder();
    // Update pattern index
    for (int i=0;i<m_curPatterns.count();i++) {
        m_ttr.m_orders[m_ttr.m_currentOrder][i] = m_curPatterns[i]->getPatternCmb()->currentIndex();
    }

    ReloadPatterns();
}

void FormTTREdit::ApplyCurrentOrder()
{
    SaveCurrentInstrument();
    m_ttr.m_text = ui->leText->toPlainText();
    if (m_curPatterns.count()==0)
        return;
    QByteArray order;
    for (int i=0;i<m_curPatterns.count();i++) {
//        int pat = m_curPatterns[i]->getPatternCmb()->currentIndex();
        int pat = m_curPatternValues[i];
        qDebug() << "CurrentPat To Save" << pat;
        m_ttr.m_patterns[pat] = m_curPatterns[i]->getData();
        order.append(pat);
    }
    m_ttr.m_orders[m_ttr.m_currentOrder] = order;
}


void FormTTREdit::on_cmbPattern_currentIndexChanged(int index)
{
    ApplyCurrentOrder();
    m_ttr.m_currentOrder = index;
    ReloadPatterns();
}

void FormTTREdit::on_cmbInstruments_currentIndexChanged(int index)
{

    // First, save old
    SaveCurrentInstrument();
    QString txt = "";
    for (int i=11;i<m_ttr.m_instruments[index].count();i++)
        txt+=QChar(m_ttr.m_instruments[index][i]);

/*    unsigned int d = ((uchar)m_ttr.m_instruments[index][0]) |
            ((uchar)m_ttr.m_instruments[index][1])<<8|
            ((uchar)m_ttr.m_instruments[index][2])<<16|
            ((uchar)m_ttr.m_instruments[index][3])<<24;
*/

    ui->leInstrument->setText(txt);
//    ui->leInstrumentData->setText(QString::number(d,16));
    QByteArray ba = m_ttr.m_instruments[index].mid(0,11);
    ui->leInstrumentData->setText(Util::toString(Util::ByteArrayToHexQStringList(ba)));
    m_currentInstrument = index;
}

void FormTTREdit::on_btnNewPattern_clicked()
{
    m_ttr.InsertPattern(m_ttr.m_patterns.count());
    ReloadPatterns();
}