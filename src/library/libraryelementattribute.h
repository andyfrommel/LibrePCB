/*
 * EDA4U - Professional EDA for everyone!
 * Copyright (C) 2013 Urban Bruhin
 * http://eda4u.ubruhin.ch/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBRARY_ATTRIBUTE_H
#define LIBRARY_ATTRIBUTE_H

/*****************************************************************************************
 *  Includes
 ****************************************************************************************/

#include <QtCore>
#include "../common/exceptions.h"
#include "../common/file_io/if_xmlserializableobject.h"

/*****************************************************************************************
 *  Forward Declarations
 ****************************************************************************************/

namespace library {
class GenericComponent;
}

/*****************************************************************************************
 *  Class Attribute
 ****************************************************************************************/

namespace library {

/**
 * @brief The Attribute class represents an attribute of a library element
 */
class Attribute final : public IF_XmlSerializableObject
{
        Q_DECLARE_TR_FUNCTIONS(Attribute)

    public:

        /// @brief Available Attribute Types
        enum class Type_t {
            String = 0,
            Length,
            Resistance,
            Capacitance,
            Inductance,
            _COUNT
        };


        // Constructors / Destructor
        explicit Attribute(const XmlDomElement& domElement) throw (Exception);
        ~Attribute() noexcept;


        // Getters
        const QString& getKey() const noexcept {return mKey;}
        Type_t getType() const noexcept {return mType;}
        QString getName(const QString& locale = QString()) const noexcept;
        QString getDescription(const QString& locale = QString()) const noexcept;
        QString getDefaultValue(const QString& locale = QString()) const noexcept;
        const QHash<QString, QString>& getNames() const noexcept {return mNames;}
        const QHash<QString, QString>& getDescriptions() const noexcept {return mDescriptions;}
        const QHash<QString, QString>& getDefaultValues() const noexcept {return mDefaultValues;}

        // General Methods
        XmlDomElement* serializeToXmlDomElement() const throw (Exception);

        // Static Methods
        static Type_t stringToType(const QString& type) throw (Exception);
        static QString typeToString(Type_t type) noexcept;


    private:

        // make some methods inaccessible...
        Attribute();
        Attribute(const Attribute& other);
        Attribute& operator=(const Attribute& rhs);

        // Private Methods
        bool checkAttributesValidity() const noexcept;


        // Attributes
        QString mKey;
        Type_t mType;
        QHash<QString, QString> mNames;
        QHash<QString, QString> mDescriptions;
        QHash<QString, QString> mDefaultValues;
};

} // namespace library

#endif // LIBRARY_ATTRIBUTE_H