/*
 * Turbo Rascal Syntax error, “;” expected but “BEGIN” (TRSE, Turbo Rascal SE)
 * 8 bit software development IDE for the Commodore 64
 * Copyright (C) 2018  Nicolaas Ervik Groeneboom (nicolaas.groeneboom@gmail.com)
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program (LICENSE.txt).
 *   If not, see <https://www.gnu.org/licenses/>.
*/

#include "nodenumber.h"


NodeNumber::NodeNumber(Token op, long val) :Node() {
    m_op = op;
    m_val = val;


    if (m_op.m_type!=TokenType::ADDRESS)
        m_op.m_type = TokenType::INTEGER_CONST;

}


bool NodeNumber::isAddress() {
    return m_op.m_type == TokenType::ADDRESS;
}



bool NodeNumber::isPureNumeric() {
    return true;
}

bool NodeNumber::isWord(Assembler *as) {
//    return (m_val>=256 && m_op.m_type == TokenType::INTEGER_CONST);
    if (m_forceType == TokenType::INTEGER)
        return true;
    return (m_val>=256 && m_op.m_type == TokenType::INTEGER_CONST);
}

QString NodeNumber::getValue(Assembler* as) {
        QString hash = "";
        if (as!=nullptr)
            hash = as->m_hash;
        if (isAddress()) return HexValue(); else return hash + HexValue();
    }

QString NodeNumber::getValue8bit(Assembler *as, bool isHi) {
    QString hash = "";
    if (as!=nullptr)
        hash = as->m_hash;

    if (isAddress()) hash="";
    if (isHi)
        return hash + Util::numToHex((int)m_val>>8);
    else
        return hash + Util::numToHex(((int)m_val)&0xFF);
}





bool NodeNumber::is8bitValue(Assembler* as)
{
    //  if (m_forceType==TokenType::INTEGER)
    //        return false;
    return m_val<256 && m_op.m_type == TokenType::INTEGER_CONST;
}

/*void NodeNumber::LoadVariable(AbstractASTDispatcher* dispatcher) {
    dispatcher->as->ClearTerm();
    dispatcher->as->Term("lda ");
    Accept(dispatcher);
//    Build(as);
    dispatcher->as->Term();
}
*/
QString NodeNumber::HexValue() {

//    qDebug() << "NODENUMBER " <<m_val;
    if (m_val>=0)



    return "$" + QString::number((long)m_val,16);
    else
        return "-$" + QString::number((long)abs(m_val),16);

}

bool NodeNumber::DataEquals(QSharedPointer<Node> other) {
    QSharedPointer<NodeNumber> var = qSharedPointerDynamicCast<NodeNumber>(other);
    if (var==nullptr)
        return false;
    return var->m_val == m_val;
}

QString NodeNumber::StringValue() {
    QString val;
    if (m_op.m_type==TokenType::BYTE)
        val = "#"+QString::number((int)m_val);
    if (m_op.m_type==TokenType::INTEGER)
        val = "#"+QString::number((int)m_val);
    if (m_op.m_type==TokenType::INTEGER_CONST)
        val = "#"+QString::number((int)m_val);
    if (m_op.m_type==TokenType::ADDRESS) {
        val = "$" + QString::number((int)m_val,16);
    }
    return val;
}

bool NodeNumber::isMinusOne() {
    if (m_val==255)
        return true;

    return false;
}

bool NodeNumber::isOne() { return m_val==1; }

