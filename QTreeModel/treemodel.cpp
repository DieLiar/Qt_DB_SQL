#include "treeitem.h"
#include "treemodel.h"
#include <QDebug>

TreeModel::TreeModel(QObject *parent): QAbstractItemModel(parent)
{
    QVector <QVariant> rootData;
    rootData << "id" << "Name";
    rootItem = new TreeItem(rootData);
}

TreeModel::~TreeModel()
{
    delete rootItem;
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    return rootItem->columnCount();
}

QVariant TreeModel::data (const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role != Qt::DisplayRole  && role != Qt::EditRole)
        return QVariant();
    TreeItem *item = getItem(index);
    return item->data(index.column());
}

TreeItem *TreeModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()){
        TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return rootItem;
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemFlags(0);
    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);
    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();
    TreeItem *parentItem = getItem(parent);
    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();
    TreeItem *childItem = getItem(index);
    TreeItem *parentItem = childItem->parentItem();
    if (parentItem == rootItem)
        return QModelIndex();
    return createIndex(parentItem->childNumber(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem = getItem(parent);
    return parentItem->childCount();
}

bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;
    TreeItem *item = getItem(index);
    bool result = item->setData(index.column(), value);
    if (result) {
        emit dataChanged(index, index);
    }
    return result;
}

bool TreeModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal) return false;
    bool result = rootItem->setData(section, value);
    if (result) {
        emit headerDataChanged(orientation, section, section);
    }
 return result;
}

bool TreeModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    TreeItem *parentItem = getItem(parent);
    bool success;
    beginInsertRows(parent, position, position + rows - 1);
    success = parentItem->insertChildren(position, rows, rootItem->columnCount());
    endInsertRows();
    return success;
}

bool TreeModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    TreeItem *parentItem = getItem(parent);
    bool success = true;
    beginRemoveRows(parent, position, position + rows - 1);
    success = parentItem->removeChildren(position, rows);
    endRemoveRows();
    return success;
}

