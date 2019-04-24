/**
 \file ArrayDeque.h
 \author Allemann Alexis, Alexandre Mottier, Johann Werkle
 \date 11.04.2019 - 28.04.2019
 \brief Fichier d'entête de la classe ArrayDeque
 \details La déclaration ainsi que l'implémentation de la classe sont définis dans ce
 *       fichier
 \mainpage Labo4 - Allemann, Mottier, Werkle
 \version 1.0
 */

#ifndef ArrayDeque_hpp
#define ArrayDeque_hpp

#include <vector>
#include <string.h>
//#include <stdexcept>

template < class T >
class ArrayDeque {
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    
    
private:
    std::vector<value_type> buffer;
    size_type debut;
    size_type taille;
    
public:
    
    ArrayDeque(size_type capacity = 0) : debut(0), taille(0), buffer(capacity) {
        buffer.resize(capacity);
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
    
    reference back() {
        if (buffer.empty()){
            throw;
        }
        return buffer.at(taille - 1);
    }
    
    const_reference back() const {
        if (buffer.empty()){
            throw;
        }
        return buffer.at(taille - 1);
    }
    
    reference front() {
        if (buffer.empty()){
            throw;
        }
        return buffer.at(debut);
    }
    
    const_reference front() const {
        if (buffer.empty()){
            throw;
        }
        return buffer.at(debut);
    }
    
    
    void push_back(value_type val) {
        if (taille++ == capacity())
        {
            increaseCapacity();
        }
        size_type bufferPosition = getBufferPosition(debut + taille - 1);
        buffer.at(bufferPosition) = val;
    }
    
    void push_front(value_type val) {
        if (taille++ == capacity())
        {
            increaseCapacity();
        }
        size_type posInsertion = 0;
        if (!debut)
        {
            posInsertion = capacity() - 1;
        }
        else
        {
            posInsertion = debut - 1;
        }
        buffer.at(posInsertion) = val;
        debut = posInsertion;
    }
    
    void pop_back() {
        if (taille > 0)
        {
            taille--;
        }
    }
    
    void pop_front() {
        if (taille > 0)
        {
            debut = getBufferPosition(debut + 1);
            taille--;
        }
    }
    
    void increaseCapacity() {
        // Copie des valeurs du vecteur de base (copie en 0 de l'indice logique 0)
        std::vector<value_type> temp(capacity());
        for (size_type i = 0; i < taille - 1; i++)
        {
            size_type bufferPosition = getBufferPosition(debut + i);
            temp.at(i) = buffer.at(bufferPosition);
        }
        
        size_type newCapacity = 1;
        // Par défaut à 1
        if (capacity() > 0)
        {
            newCapacity = capacity() * 2;
        }
        
        temp.resize(newCapacity);
        
        // Échange des vecteurs
        temp.swap(buffer);
        debut = 0;
    }
    
    size_type getBufferPosition(size_type indice) const {
        if (indice >= capacity())
        {
            indice = indice % capacity();
        }
        return indice;
    }
};

#endif /* ArrayDeque_hpp */
