#ifndef _ITEM
#define _ITEM

class Item
{
private :

    char typeEquipement;
    int tier;

public :

/**
 * @brief Constructeur par défaut de la classe Item.
 * Initialise le type d'équipement à 'arme' et le tier à 0
 */
        Item();

/**
 * @brief Destructeur de la classe Item.
 */
        ~Item();

/**
 * @brief Constructeur de la classe Item.
 * Initialise l'équipement et le tier selon les parametres donnés
 * @param type (char) Type de l'Item | 'w' : arme | 'a' : armure
 * @param newTier (int) Tier de l'Item
 */
        Item(const char type,const int newTier);

/**
 * @brief Constructeur par copie de la classe Item.
 * Instancie un nouvel Item en copiant celui en paramètre.
 * @param itemCp (Pointeur sur Item) Item à copier.
 */
        Item(Item * itemCp);

/**
 * @brief Mutateur du type d'équipement de la classe Item.
 * @param equipement (char) Nouveau type d'équipement.
 */
        void setTypeEquipement(const char equipement);

/**
 * @brief Mutateur du tier de la classe Item.
 * @param t (int) Nouveau tier.
 */
        void setTier(int t);

/**
 * @brief Accesseur de l'attribut typeEquipement de la classe Item.
 * @return typeEquipement (char)
 */
        char getTypeEquipement() const;

/**
 * @brief Acceseur de l'attribut tier de la classe Item.
 * @return tier (int)
 */
        int getTier() const;
};

#endif
