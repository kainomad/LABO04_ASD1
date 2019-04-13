#ifndef ArrayDeque_hpp
#define ArrayDeque_hpp

#include <vector>
#include <string.h>

template < class T >
class ArrayDeque {
public:
   using value_type = T;
   using reference = T&;
   using const_reference = const T&;
   using size_type = std::size_t;
   using difference_type = std::ptrdiff_t;

private:
   std::vector<value_type> buffer;
   size_type debut;
   size_type taille;

public:
   // méthodes et constructeur à implémenter DANS la classe (inline)

   ArrayDeque(size_type capacity = 0) : debut(0), taille(0), buffer(capacity) {
   }

   size_type size() const {
      return taille;
   }

   size_type capacity() const {
      return buffer.size();
   }

   bool empty() const {
      return taille == 0;
   }

   value_type& back() {
      return buffer.at(0);
   }

   const value_type& back() const {
      return buffer.at(0);
   }

   value_type& front() { // TODO ? Test si le buffer est vide ?
      return buffer.at(debut);
   }

   const value_type& front() const { // TODO ? Test si le buffer est vide ?
      return buffer.at(debut);
   }

   void push_back(value_type val) {
      if (++taille == capacity())
      {
         increaseCapacity();
      }
      size_t bufferPosition = getBufferPosition(debut + taille);
      buffer.at(bufferPosition) = val;
   }

   void push_front(value_type val) {
      if (++taille == capacity())
      {
         increaseCapacity();
      }
      // Faire ici le push front selon consigne
   }

   void pop_back() {
      // A faire
   }

   void pop_front() {
      // A faire
   }

   void increaseCapacity() {
      // Création d'un nouveau vecteur temporaire de la nouvelle taille
      std::vector<T> temp(2 * capacity());

      // Copie des valeurs du vecteur de base (copie en 0 de l'indice logique 0)
      for (size_t i = 0; i < capacity(); i++)
      {
         size_t bufferPosition = getBufferPosition(i);
         temp.at(i) = buffer.at(buffer.begin() + bufferPosition);
      }

      // Échange des vecteurs
      swap(buffer.begin(), temp.begin());
      swap(buffer.end(), temp.end());
      // TODO ? Echanger les capacités ?
   }

   size_t getBufferPosition(size_t indice) const {
      if (indice >= capacity())
      {
         indice %= taille;
      }
   }

};

#endif /* ArrayDeque_hpp */
