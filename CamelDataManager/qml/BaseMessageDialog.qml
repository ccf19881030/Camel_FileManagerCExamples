﻿/*!
 *@file BaseMessageDialog.qml
 *@brief 消息提醒
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
import QtQuick 2.7
import QtQuick.Controls 2.0
import Qt.labs.platform 1.0

Item{

	function showMsg(text){
		msg.text = text;
		msg.open();
	}

	MessageDialog{
		id: msg
		buttons: MessageDialog.Ok
	}
}
