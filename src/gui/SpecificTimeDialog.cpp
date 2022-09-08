/*
 * Stellarium
 * Copyright (C) 2022 Alexander Wolf
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA  02110-1335, USA.
*/

#include "StelApp.hpp"
#include "SpecificTimeDialog.hpp"

#include "ui_specificTimeDialog.h"

SpecificTimeDialog::SpecificTimeDialog(QObject* parent) : StelDialog("SpecificTime", parent)
{
	ui = new Ui_SpecificTimeDialogForm;
}

SpecificTimeDialog::~SpecificTimeDialog()
{
	delete ui;
	ui=Q_NULLPTR;
}

void SpecificTimeDialog::retranslate()
{
	if (dialog)
	{
		ui->retranslateUi(dialog);
		ui->seasonsWidget->retranslate();
	}
}

void SpecificTimeDialog::createDialogContent()
{
	ui->setupUi(dialog);
	
	//Signals and slots
	connect(&StelApp::getInstance(), SIGNAL(languageChanged()), this, SLOT(retranslate()));
	connect(ui->closeStelWindow, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui->TitleBar, SIGNAL(movedTo(QPoint)), this, SLOT(handleMovedTo(QPoint)));

	ui->seasonsWidget->setup();
}

