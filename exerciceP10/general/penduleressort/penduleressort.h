#ifndef H_PENDULERESSORT
#define H_PENDULERESSORT

#include "oscillateur.h"
#include "supportadessin.h"
#include "vecteur.h"
#include <memory>

/*!
 * Implémentation du pendule-ressort.
 */
class PenduleRessort : public Oscillateur {
public:
  PenduleRessort(double masse, double longueur, double raideur, SupportADessin* support, Vecteur position = {1.0, 0.0}, Vecteur vitesse = {0.0, 0.0}, Vecteur origine = {0.0, 0.0, 0.0}, Vecteur direction_principale = {1.0, 0.0, 0.0} );
   //! Destructeur de PenduleRessort
   virtual ~PenduleRessort() {}

   virtual Vecteur f(double temps) override;
   virtual Vecteur f(double temps, Vecteur const& position, Vecteur const& vitesse) override;

   //! Méthode de dessin qui DOIT être implémenté.
   virtual void dessine() override
   { _support->dessine(*this); }

   //! Requis pour la copie polymorphique de PenduleRessort (pour les unique_ptr, voir cours).
   std::unique_ptr<PenduleRessort> clone() const;
   //! Copie polymorphique
   virtual std::unique_ptr<Oscillateur> copie() const override;
private:
  double _m; //<! Masse du pendule-ressort.
  double _L; //<! Longueur au repos du pendule-ressort.
  double _k; //<! Constante de raideur du pendule-ressort.

  //! Utilisation du polymorphisme pour l'opérateur d'affichage.
  virtual void affiche(std::ostream& flot) const override;
};

#endif // H_PENDULERESSORT