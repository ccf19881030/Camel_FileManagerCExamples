﻿
// *@file DataTableView.cpp
// *@brief DataTableView
// *@version 1.0
// *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
// *@author zhengtianzuo
#include "DataTableView.h"
#include <QDebug>

DataTableViewModel::DataTableViewModel() : QAbstractTableModel(0) {
}

int DataTableViewModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return m_aryData.size();
}

int DataTableViewModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return(ErrorRole);
}

QVariant DataTableViewModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    if (row < 0 || row > rowCount()) return(QVariant());
    if (role < 0 || role > columnCount()) return(QVariant());
    return m_aryData[row][role];
}

QHash<int, QByteArray> DataTableViewModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[CNameRole] = "cname";
    roles[ExpectRole] = "expect";
    roles[RealRole] = "real";
    roles[ErrorRole] = "error";
    return roles;
}

void DataTableViewModel::add(QString strName, QString strCName, QString strExpect, QString strReal, int intError) {
    beginInsertRows(QModelIndex(), m_aryData.size(), m_aryData.size());
    QVector<QString> list;
    list.push_back(strName);
    list.push_back(strCName);
    list.push_back(strExpect);
    list.push_back(strReal);
    list.push_back((intError == 1) ? QStringLiteral("成功") : QStringLiteral("错误!!!"));
    m_aryData.push_back(list);
    endInsertRows();
}

void DataTableViewModel::set(int row, int column, QString strText) {
    if (row < 0 || row > rowCount()) return;
    if (column < 0 || column > columnCount()) return;
    beginResetModel();
    m_aryData[row][column] = strText;
    endResetModel();
}

void DataTableViewModel::del(int row) {
    if (row < 0 || row > rowCount()) return;
    beginRemoveRows(QModelIndex(), row, row);
    m_aryData.removeAt(row);
    endRemoveRows();
}

void DataTableViewModel::refresh() {
    beginResetModel();
    endResetModel();
}

void DataTableViewModel::clear() {
    beginResetModel();
    m_aryData.clear();
    endResetModel();
}
