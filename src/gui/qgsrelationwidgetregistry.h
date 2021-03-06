/***************************************************************************
                         qgsrelationwidgetregistry.h
                         ----------------------
    begin                : October 2020
    copyright            : (C) 2020 by Ivan Ivanov
    email                : ivan@opengis.ch
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "qgsabstractrelationeditorwidget.h"
#include "qgis_gui.h"


#ifndef QGSRELATIONWIDGETREGISTRY_H
#define QGSRELATIONWIDGETREGISTRY_H


/**
 * Keeps track of the registered relations widgets. New widgets can be registered, old ones deleted.
 * The default {\see QgsRelationEditorWidget} is protected from removing.
 * \ingroup gui
 * \class QgsRelationWidgetRegistry
 * \since QGIS 3.18
 */
class GUI_EXPORT QgsRelationWidgetRegistry
{
  public:

    /**
     * Constructor
     */
    QgsRelationWidgetRegistry();

    ~QgsRelationWidgetRegistry();

    /**
     * Adds a new registered relation \a widgetFactory
     */
    void addRelationWidget( QgsAbstractRelationEditorWidgetFactory *widgetFactory SIP_TRANSFER );

    /**
     * Removes a registered relation widget with given \a widgetType
     */
    void removeRelationWidget( const QString &widgetType );

    /**
     * Returns a list of names of registered relation widgets
     */
    QStringList relationWidgetNames();

    /**
     * Gets access to all registered factories
     */
    QMap<QString, QgsAbstractRelationEditorWidgetFactory *> factories() const;

    /**
     * Create a relation widget of a given type for a given field.
     *
     * \param widgetType  The widget type to create a relation editor for
     * \param config  The configuration of the widget
     * \param parent
     */
    QgsAbstractRelationEditorWidget *create( const QString &widgetType, const QVariantMap &config, QWidget *parent = nullptr ) const SIP_TRANSFERBACK;

    /**
     * Creates a configuration widget
     *
     * \param widgetType  The widget type to create a configuration widget for
     * \param relation  The relation for which this widget will be created
     * \param parent    The parent widget for the created widget
     */
    QgsAbstractRelationEditorConfigWidget *createConfigWidget( const QString &widgetType, const QgsRelation &relation, QWidget *parent = nullptr ) const SIP_TRANSFERBACK;

  private:

    QMap<QString, QgsAbstractRelationEditorWidgetFactory *> mRelationWidgetFactories;
};

#endif // QGSRELATIONWIDGETREGISTRY_H
