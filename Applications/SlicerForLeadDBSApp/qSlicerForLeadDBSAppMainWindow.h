/*==============================================================================

  Copyright (c) Kitware, Inc.

  See http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Julien Finet, Kitware, Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

#ifndef __qSlicerForLeadDBSAppMainWindow_h
#define __qSlicerForLeadDBSAppMainWindow_h

// SlicerForLeadDBS includes
#include "qSlicerForLeadDBSAppExport.h"
class qSlicerForLeadDBSAppMainWindowPrivate;

// Slicer includes
#include "qSlicerMainWindow.h"

class Q_SLICERFORLEADDBS_APP_EXPORT qSlicerForLeadDBSAppMainWindow : public qSlicerMainWindow
{
  Q_OBJECT
public:
  typedef qSlicerMainWindow Superclass;

  qSlicerForLeadDBSAppMainWindow(QWidget *parent=0);
  virtual ~qSlicerForLeadDBSAppMainWindow();

public slots:
  void on_HelpAboutSlicerForLeadDBSAppAction_triggered();

protected:
  qSlicerForLeadDBSAppMainWindow(qSlicerForLeadDBSAppMainWindowPrivate* pimpl, QWidget* parent);

private:
  Q_DECLARE_PRIVATE(qSlicerForLeadDBSAppMainWindow);
  Q_DISABLE_COPY(qSlicerForLeadDBSAppMainWindow);
};

#endif
