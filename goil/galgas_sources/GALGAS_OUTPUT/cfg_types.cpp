//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'cfg_types.cpp'                            *
//                        Generated by version 1.8.2                         *
//                      april 27th, 2009, at 22h49'17"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 463
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "cfg_types.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "cfg_types.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                             class 'e_config'                              *
//                                                                           *
//---------------------------------------------------------------------------*

e_config::e_config (void) :
value () {
}

//---------------------------------------------------------------------------*
//                                                                           *
//                           class map '@config'                             *
//                                                                           *
//---------------------------------------------------------------------------*

elementOf_GGS_config::
elementOf_GGS_config (const GGS_lstring & inKey,
              const sint32 inIndex,
              const e_config & inInfo) :
AC_galgas_map_element (inKey, inIndex),
mInfo (inInfo) {
}

//---------------------------------------------------------------------------*

void elementOf_GGS_config::
appendForMapDescription (C_Compiler & _inLexique,
                         const sint32 inElementIndex,
                         C_String & ioString,
                         const sint32 inIndentation
                         COMMA_LOCATION_ARGS) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "|-key " << inElementIndex << ":" << mKey.reader_description  (_inLexique COMMA_THERE, inIndentation + 1) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "|-value " << inElementIndex << ":" << mInfo.value.reader_description  (_inLexique COMMA_THERE, inIndentation + 1) ;
}

//---------------------------------------------------------------------------*

bool elementOf_GGS_config::
isEqualToMapElement (const AC_galgas_map_element * inOperand) const {
  const elementOf_GGS_config * _p = dynamic_cast <const elementOf_GGS_config *> (inOperand) ;
  macroValidPointer (_p) ;
  return (mInfo.value._operator_isEqual (_p->mInfo.value)).boolValue () ;
}

//---------------------------------------------------------------------------*

AC_galgas_map_element * GGS_config::
new_element (const GGS_lstring & inKey, void * inInfo) {
  MF_Assert (reinterpret_cast <e_config *> (inInfo) != NULL, "Dynamic cast error", 0, 0) ;
  AC_galgas_map_element * p = NULL ;
  e_config * info = (e_config *) inInfo ;
  macroMyNew (p, cElement (inKey, nextIndex (), * info)) ;
  return p ;
}

//---------------------------------------------------------------------------*

void GGS_config::
assignInfo (AC_galgas_map_element * inPtr, void * inInfo) {
  MF_Assert (reinterpret_cast <cElement *> (inPtr) != NULL, "Dynamic cast error", 0, 0) ;
  MF_Assert (reinterpret_cast <e_config *> (inInfo) != NULL, "Dynamic cast error", 0, 0) ;
  cElement * p = (cElement *) inPtr ;
  e_config * info = (e_config *) inInfo ;
  p->mInfo = * info ;
}

//---------------------------------------------------------------------------*

GGS_config GGS_config::
constructor_emptyMap (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) {
  GGS_config result ;
  macroMyNew (result.mSharedMapRoot, cMapRoot) ;
  return result ;
}

//---------------------------------------------------------------------------*

void GGS_config::
enterIndex (const GGS_lstring & inKey,
            AC_galgas_index_core & outIndex) {
  e_config info  ;
  internalEnterIndex (inKey,
                      (void *) & info,
                      mSharedMapRoot->_mRoot,
                      outIndex) ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
_operator_isEqual (const GGS_config & inOperand) const {
  return GGS_bool (_isBuilt () && inOperand._isBuilt (), isEqualToMap (inOperand)) ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
_operator_isNotEqual (const GGS_config & inOperand) const {
  return GGS_bool (_isBuilt () && inOperand._isBuilt (), ! isEqualToMap (inOperand)) ;
}

//---------------------------------------------------------------------------*

void GGS_config::
internalInsertForDuplication (AC_galgas_map_element * inPtr) {
  MF_Assert (reinterpret_cast <cElement *> (inPtr) != NULL, "Dynamic cast error", 0, 0) ;
  cElement * p = (cElement *) inPtr ;
  sint32 attributeIndex = -1 ; // Unused here
  GGS_location existingKeyLocation ; // Unused here
  internalInsert (p->mKey, (void *) & p->mInfo,mSharedMapRoot->_mRoot, attributeIndex, existingKeyLocation) ;
}

//---------------------------------------------------------------------------*

void GGS_config::
_removeElement (C_Compiler & inLexique,
                const char * inErrorMessage,
                const GGS_lstring & inKey,
                GGS_basic_type & outParameter0,
                GGS_luint * outIndex
                COMMA_LOCATION_ARGS) {
  AC_galgas_map_element * removedElement = NULL ;
  sint32 elementID = - 1 ;
  if (_isBuilt () && inKey._isBuilt ()) {
    insulateMap () ;
    bool unused ;
    _internalRemove (mSharedMapRoot->_mRoot, inKey, removedElement, unused) ;
    if (removedElement == NULL) {
      emitMapSemanticErrorMessage (inLexique, inKey, inErrorMessage COMMA_THERE) ;
      outParameter0._drop () ;
    }else{
      cElement * _p = (cElement *) removedElement ;
      elementID = _p->mID ;
      outParameter0 = _p->mInfo.value ;
    }
  }
  if (outIndex != NULL) {
    * outIndex = GGS_luint (GGS_uint (elementID >= 0, (uint32) elementID), inKey) ;
  }
  macroMyDelete (removedElement, cElement) ;
}

//---------------------------------------------------------------------------*

void GGS_config::
_insertElement (C_Compiler & inLexique,
                const char * inErrorMessage,
                const GGS_lstring & inKey,
                const GGS_basic_type & inParameter0,
                GGS_luint * outIndex
                COMMA_LOCATION_ARGS) {
  sint32 elementID = - 1 ;
  if (_isBuilt ()
   && inParameter0._isBuilt ()
   && inKey._isBuilt ()) {
    insulateMap () ;
    e_config info  ;
    info.value = inParameter0 ;
    GGS_location existingKeyLocation ;
    internalInsert (inKey, (void *) & info, mSharedMapRoot->_mRoot, elementID, existingKeyLocation) ;
    if (elementID < 0) {
      emitInsertMapSemanticErrorMessage (inLexique, inKey, inErrorMessage, existingKeyLocation COMMA_THERE) ;
    }
  }
  if (outIndex != NULL) {
    * outIndex = GGS_luint (GGS_uint (elementID >= 0, (uint32) elementID), inKey) ;
  }
}

//---------------------------------------------------------------------------*

void GGS_config::
_searchElement (C_Compiler & inLexique,
               const char * inErrorMessage,
               const GGS_lstring & inKey,
               GGS_basic_type   & outParameter0,
               GGS_luint * outIndex
               COMMA_LOCATION_ARGS) const {
  cElement * node = NULL  ;
  if (_isBuilt () && inKey._isBuilt ()) {
    AC_galgas_map_element * p = internal_search (inKey.string ()) ;
    MF_Assert ((p == NULL) || (reinterpret_cast <cElement *> (p) != NULL), "Dynamic cast error", 0, 0) ;
    node = (cElement *) p ;
    if (node == NULL) {
      emitMapSemanticErrorMessage (inLexique, inKey, inErrorMessage COMMA_THERE) ;
    }
  }
  if (node == NULL) {
    outParameter0._drop () ;
    if (outIndex != NULL) {
      outIndex->_drop () ;
     }
  }else{
    outParameter0 = node->mInfo.value ;
    if (outIndex != NULL) {
      * outIndex = GGS_luint (GGS_uint (true, (uint32) node->mID), inKey) ;
    }
  }
}

//---------------------------------------------------------------------------*

void GGS_config::
modifier_setValueForKey (C_Compiler & inLexique,
                        const GGS_basic_type & inValue,
                        const GGS_string & inKey
                        COMMA_LOCATION_ARGS) {
  if (_isBuilt () && inValue._isBuilt () && inKey._isBuilt ()) {
    insulateMap () ;
    AC_galgas_map_element * p = internal_search (inKey.string ()) ;
    MF_Assert ((p == NULL) || (reinterpret_cast <cElement *> (p) != NULL), "Dynamic cast error", 0, 0) ;
    cElement * node = (cElement *) p ;
    if (node == NULL) {
      C_String errorMessage ;
      errorMessage << "the '" << inKey << "' key does not exist when calling 'setValueForKey' modifier" ;
      inLexique.onTheFlyRunTimeError (errorMessage COMMA_THERE) ;
    }else{
      node->mInfo.value = inValue ;
    }
  }
}

//---------------------------------------------------------------------------*

void GGS_config::
method_get (C_Compiler & inLexique,
                                const GGS_lstring & inKey,
                                GGS_basic_type   & outParameter0 COMMA_LOCATION_ARGS) const {
  _searchElement (inLexique,
                  "Key %K is not defined",
                  inKey,
                  outParameter0,
                  NULL
                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------*

void GGS_config::
modifier_del (C_Compiler & _inLexique,
                                const GGS_lstring & inKey,
                                GGS_basic_type & outParameter0 COMMA_LOCATION_ARGS) {
  _removeElement (_inLexique,
                  "Key %K is not defined",
                  inKey,
                  outParameter0,
                  NULL
                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------*

void GGS_config::
modifier_put (C_Compiler & _inLexique,
                                const GGS_lstring & inKey,
                                const GGS_basic_type & inParameter0 COMMA_LOCATION_ARGS) {
  _insertElement (_inLexique,
                 "Key %K is duplicated in %L",
                 inKey,
                 inParameter0,
                 NULL
                 COMMA_THERE) ;
}

//---------------------------------------------------------------------------*

GGS_config GGS_config::
constructor_mapWithMapToOverride (C_Compiler & /* inLexique */,
                                  const GGS_config & inMapToOverride
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GGS_config result ; // Not Built
  if (inMapToOverride.mSharedMapRoot != NULL) {
    macroValidPointer (inMapToOverride.mSharedMapRoot) ;
    macroMyNew (result.mSharedMapRoot, cMapRoot) ;
    result.mSharedMapRoot->mNextMap = inMapToOverride.mSharedMapRoot ;
    inMapToOverride.mSharedMapRoot->mReferenceCount ++ ;
    result.mSharedMapRoot->mSequenceNumber = inMapToOverride.mSharedMapRoot->mSequenceNumber ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_config GGS_config::
reader_overriddenMap (C_Compiler & /* inLexique */
                      COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_config result ; // Not Built
  if (mSharedMapRoot != NULL) {
    macroValidPointer (mSharedMapRoot) ;
    result.mSharedMapRoot = mSharedMapRoot->mNextMap ;
    if (result.mSharedMapRoot != NULL) {
      macroValidPointer (result.mSharedMapRoot) ;
      result.mSharedMapRoot->mReferenceCount ++ ;
    }else{
      macroMyNew (result.mSharedMapRoot, cMapRoot) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_string GGS_config::
reader_description (C_Compiler & _inLexique
                    COMMA_LOCATION_ARGS,
                    const sint32 inIndentation) const {
  C_String s ;
  s << "<map @config " ;
  if (_isBuilt ()) {
    s << count () << " object" << ((count () > 1) ? "s " : " ") ;
    cElement * p = firstObject () ;
    sint32 elementID = 0 ;
    while (p != NULL) {
      macroValidPointer (p) ;
      p->appendForMapDescription (_inLexique, elementID, s, inIndentation COMMA_THERE) ;
      p = p->nextObject () ;
      elementID ++ ;
    }
  }else{
    s << "not built" ;
  }
  s << "\n" ;
  s.writeStringMultiple ("| ", inIndentation) ;
  s << ">" ;
  return GGS_string (true, s) ;
}

//---------------------------------------------------------------------------*

/* const */ GGS_basic_type  & GGS_config::cEnumerator::_value (LOCATION_ARGS) const {
  return ((cElement *) mObjectArray (mCurrentIndex COMMA_THERE))->mInfo.value ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                           class 'e_cfg_attrs'                             *
//                                                                           *
//---------------------------------------------------------------------------*

e_cfg_attrs::e_cfg_attrs (void) :
tpl_attr () {
}

//---------------------------------------------------------------------------*
//                                                                           *
//                          class map '@cfg_attrs'                           *
//                                                                           *
//---------------------------------------------------------------------------*

elementOf_GGS_cfg_attrs::
elementOf_GGS_cfg_attrs (const GGS_lstring & inKey,
              const sint32 inIndex,
              const e_cfg_attrs & inInfo) :
AC_galgas_map_element (inKey, inIndex),
mInfo (inInfo) {
}

//---------------------------------------------------------------------------*

void elementOf_GGS_cfg_attrs::
appendForMapDescription (C_Compiler & _inLexique,
                         const sint32 inElementIndex,
                         C_String & ioString,
                         const sint32 inIndentation
                         COMMA_LOCATION_ARGS) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "|-key " << inElementIndex << ":" << mKey.reader_description  (_inLexique COMMA_THERE, inIndentation + 1) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "|-value " << inElementIndex << ":" << mInfo.tpl_attr.reader_description  (_inLexique COMMA_THERE, inIndentation + 1) ;
}

//---------------------------------------------------------------------------*

bool elementOf_GGS_cfg_attrs::
isEqualToMapElement (const AC_galgas_map_element * inOperand) const {
  const elementOf_GGS_cfg_attrs * _p = dynamic_cast <const elementOf_GGS_cfg_attrs *> (inOperand) ;
  macroValidPointer (_p) ;
  return (mInfo.tpl_attr._operator_isEqual (_p->mInfo.tpl_attr)).boolValue () ;
}

//---------------------------------------------------------------------------*

AC_galgas_map_element * GGS_cfg_attrs::
new_element (const GGS_lstring & inKey, void * inInfo) {
  MF_Assert (reinterpret_cast <e_cfg_attrs *> (inInfo) != NULL, "Dynamic cast error", 0, 0) ;
  AC_galgas_map_element * p = NULL ;
  e_cfg_attrs * info = (e_cfg_attrs *) inInfo ;
  macroMyNew (p, cElement (inKey, nextIndex (), * info)) ;
  return p ;
}

//---------------------------------------------------------------------------*

void GGS_cfg_attrs::
assignInfo (AC_galgas_map_element * inPtr, void * inInfo) {
  MF_Assert (reinterpret_cast <cElement *> (inPtr) != NULL, "Dynamic cast error", 0, 0) ;
  MF_Assert (reinterpret_cast <e_cfg_attrs *> (inInfo) != NULL, "Dynamic cast error", 0, 0) ;
  cElement * p = (cElement *) inPtr ;
  e_cfg_attrs * info = (e_cfg_attrs *) inInfo ;
  p->mInfo = * info ;
}

//---------------------------------------------------------------------------*

GGS_cfg_attrs GGS_cfg_attrs::
constructor_emptyMap (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) {
  GGS_cfg_attrs result ;
  macroMyNew (result.mSharedMapRoot, cMapRoot) ;
  return result ;
}

//---------------------------------------------------------------------------*

void GGS_cfg_attrs::
enterIndex (const GGS_lstring & inKey,
            AC_galgas_index_core & outIndex) {
  e_cfg_attrs info  ;
  internalEnterIndex (inKey,
                      (void *) & info,
                      mSharedMapRoot->_mRoot,
                      outIndex) ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_cfg_attrs::
_operator_isEqual (const GGS_cfg_attrs & inOperand) const {
  return GGS_bool (_isBuilt () && inOperand._isBuilt (), isEqualToMap (inOperand)) ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_cfg_attrs::
_operator_isNotEqual (const GGS_cfg_attrs & inOperand) const {
  return GGS_bool (_isBuilt () && inOperand._isBuilt (), ! isEqualToMap (inOperand)) ;
}

//---------------------------------------------------------------------------*

void GGS_cfg_attrs::
internalInsertForDuplication (AC_galgas_map_element * inPtr) {
  MF_Assert (reinterpret_cast <cElement *> (inPtr) != NULL, "Dynamic cast error", 0, 0) ;
  cElement * p = (cElement *) inPtr ;
  sint32 attributeIndex = -1 ; // Unused here
  GGS_location existingKeyLocation ; // Unused here
  internalInsert (p->mKey, (void *) & p->mInfo,mSharedMapRoot->_mRoot, attributeIndex, existingKeyLocation) ;
}

//---------------------------------------------------------------------------*

void GGS_cfg_attrs::
_removeElement (C_Compiler & inLexique,
                const char * inErrorMessage,
                const GGS_lstring & inKey,
                GGS_lstring & outParameter0,
                GGS_luint * outIndex
                COMMA_LOCATION_ARGS) {
  AC_galgas_map_element * removedElement = NULL ;
  sint32 elementID = - 1 ;
  if (_isBuilt () && inKey._isBuilt ()) {
    insulateMap () ;
    bool unused ;
    _internalRemove (mSharedMapRoot->_mRoot, inKey, removedElement, unused) ;
    if (removedElement == NULL) {
      emitMapSemanticErrorMessage (inLexique, inKey, inErrorMessage COMMA_THERE) ;
      outParameter0._drop () ;
    }else{
      cElement * _p = (cElement *) removedElement ;
      elementID = _p->mID ;
      outParameter0 = _p->mInfo.tpl_attr ;
    }
  }
  if (outIndex != NULL) {
    * outIndex = GGS_luint (GGS_uint (elementID >= 0, (uint32) elementID), inKey) ;
  }
  macroMyDelete (removedElement, cElement) ;
}

//---------------------------------------------------------------------------*

void GGS_cfg_attrs::
_insertElement (C_Compiler & inLexique,
                const char * inErrorMessage,
                const GGS_lstring & inKey,
                const GGS_lstring & inParameter0,
                GGS_luint * outIndex
                COMMA_LOCATION_ARGS) {
  sint32 elementID = - 1 ;
  if (_isBuilt ()
   && inParameter0._isBuilt ()
   && inKey._isBuilt ()) {
    insulateMap () ;
    e_cfg_attrs info  ;
    info.tpl_attr = inParameter0 ;
    GGS_location existingKeyLocation ;
    internalInsert (inKey, (void *) & info, mSharedMapRoot->_mRoot, elementID, existingKeyLocation) ;
    if (elementID < 0) {
      emitInsertMapSemanticErrorMessage (inLexique, inKey, inErrorMessage, existingKeyLocation COMMA_THERE) ;
    }
  }
  if (outIndex != NULL) {
    * outIndex = GGS_luint (GGS_uint (elementID >= 0, (uint32) elementID), inKey) ;
  }
}

//---------------------------------------------------------------------------*

void GGS_cfg_attrs::
_searchElement (C_Compiler & inLexique,
               const char * inErrorMessage,
               const GGS_lstring & inKey,
               GGS_lstring   & outParameter0,
               GGS_luint * outIndex
               COMMA_LOCATION_ARGS) const {
  cElement * node = NULL  ;
  if (_isBuilt () && inKey._isBuilt ()) {
    AC_galgas_map_element * p = internal_search (inKey.string ()) ;
    MF_Assert ((p == NULL) || (reinterpret_cast <cElement *> (p) != NULL), "Dynamic cast error", 0, 0) ;
    node = (cElement *) p ;
    if (node == NULL) {
      emitMapSemanticErrorMessage (inLexique, inKey, inErrorMessage COMMA_THERE) ;
    }
  }
  if (node == NULL) {
    outParameter0._drop () ;
    if (outIndex != NULL) {
      outIndex->_drop () ;
     }
  }else{
    outParameter0 = node->mInfo.tpl_attr ;
    if (outIndex != NULL) {
      * outIndex = GGS_luint (GGS_uint (true, (uint32) node->mID), inKey) ;
    }
  }
}

//---------------------------------------------------------------------------*

void GGS_cfg_attrs::
modifier_setTpl_attrForKey (C_Compiler & inLexique,
                        const GGS_lstring & inValue,
                        const GGS_string & inKey
                        COMMA_LOCATION_ARGS) {
  if (_isBuilt () && inValue._isBuilt () && inKey._isBuilt ()) {
    insulateMap () ;
    AC_galgas_map_element * p = internal_search (inKey.string ()) ;
    MF_Assert ((p == NULL) || (reinterpret_cast <cElement *> (p) != NULL), "Dynamic cast error", 0, 0) ;
    cElement * node = (cElement *) p ;
    if (node == NULL) {
      C_String errorMessage ;
      errorMessage << "the '" << inKey << "' key does not exist when calling 'setTpl_attrForKey' modifier" ;
      inLexique.onTheFlyRunTimeError (errorMessage COMMA_THERE) ;
    }else{
      node->mInfo.tpl_attr = inValue ;
    }
  }
}

//---------------------------------------------------------------------------*

void GGS_cfg_attrs::
method_get (C_Compiler & inLexique,
                                const GGS_lstring & inKey,
                                GGS_lstring   & outParameter0 COMMA_LOCATION_ARGS) const {
  _searchElement (inLexique,
                  "Attribute %K is not defined",
                  inKey,
                  outParameter0,
                  NULL
                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------*

void GGS_cfg_attrs::
modifier_del (C_Compiler & _inLexique,
                                const GGS_lstring & inKey,
                                GGS_lstring & outParameter0 COMMA_LOCATION_ARGS) {
  _removeElement (_inLexique,
                  "Attribute %K is not defined",
                  inKey,
                  outParameter0,
                  NULL
                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------*

void GGS_cfg_attrs::
modifier_put (C_Compiler & _inLexique,
                                const GGS_lstring & inKey,
                                const GGS_lstring & inParameter0 COMMA_LOCATION_ARGS) {
  _insertElement (_inLexique,
                 "Attribute %K redefined in %L",
                 inKey,
                 inParameter0,
                 NULL
                 COMMA_THERE) ;
}

//---------------------------------------------------------------------------*

GGS_cfg_attrs GGS_cfg_attrs::
constructor_mapWithMapToOverride (C_Compiler & /* inLexique */,
                                  const GGS_cfg_attrs & inMapToOverride
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GGS_cfg_attrs result ; // Not Built
  if (inMapToOverride.mSharedMapRoot != NULL) {
    macroValidPointer (inMapToOverride.mSharedMapRoot) ;
    macroMyNew (result.mSharedMapRoot, cMapRoot) ;
    result.mSharedMapRoot->mNextMap = inMapToOverride.mSharedMapRoot ;
    inMapToOverride.mSharedMapRoot->mReferenceCount ++ ;
    result.mSharedMapRoot->mSequenceNumber = inMapToOverride.mSharedMapRoot->mSequenceNumber ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_cfg_attrs GGS_cfg_attrs::
reader_overriddenMap (C_Compiler & /* inLexique */
                      COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_cfg_attrs result ; // Not Built
  if (mSharedMapRoot != NULL) {
    macroValidPointer (mSharedMapRoot) ;
    result.mSharedMapRoot = mSharedMapRoot->mNextMap ;
    if (result.mSharedMapRoot != NULL) {
      macroValidPointer (result.mSharedMapRoot) ;
      result.mSharedMapRoot->mReferenceCount ++ ;
    }else{
      macroMyNew (result.mSharedMapRoot, cMapRoot) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_string GGS_cfg_attrs::
reader_description (C_Compiler & _inLexique
                    COMMA_LOCATION_ARGS,
                    const sint32 inIndentation) const {
  C_String s ;
  s << "<map @cfg_attrs " ;
  if (_isBuilt ()) {
    s << count () << " object" << ((count () > 1) ? "s " : " ") ;
    cElement * p = firstObject () ;
    sint32 elementID = 0 ;
    while (p != NULL) {
      macroValidPointer (p) ;
      p->appendForMapDescription (_inLexique, elementID, s, inIndentation COMMA_THERE) ;
      p = p->nextObject () ;
      elementID ++ ;
    }
  }else{
    s << "not built" ;
  }
  s << "\n" ;
  s.writeStringMultiple ("| ", inIndentation) ;
  s << ">" ;
  return GGS_string (true, s) ;
}

//---------------------------------------------------------------------------*

/* const */ GGS_lstring  & GGS_cfg_attrs::cEnumerator::_tpl_attr (LOCATION_ARGS) const {
  return ((cElement *) mObjectArray (mCurrentIndex COMMA_THERE))->mInfo.tpl_attr ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                            class 'cPtr_attrs'                             *
//                                                                           *
//---------------------------------------------------------------------------*

cPtr_attrs::
cPtr_attrs (const GGS_location & argument_0,
                                const GGS_cfg_attrs & argument_1
                                COMMA_LOCATION_ARGS)
:cPtr_basic_type (argument_0 COMMA_THERE),
attrs (argument_1) {
}

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  cPtr_attrs * GGS_attrs::
  operator () (LOCATION_ARGS) const {
    macroValidPointerThere (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_attrs *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    return (cPtr_attrs *) mPointer ;
  }
#endif

//---------------------------------------------------------------------------*

bool cPtr_attrs::
isEqualToObject (const cPtr__AC_galgas_class * inOperand) const {
  bool equal = typeid (this) == typeid (inOperand) ;
  if (equal) {
    const cPtr_attrs * _p = dynamic_cast <const cPtr_attrs *> (inOperand) ;
    macroValidPointer (_p) ;
    equal = location._operator_isEqual (_p->location).boolValue ()
         && attrs._operator_isEqual (_p->attrs).boolValue () ;
  }
  return equal ;
}

//---------------------------------------------------------------------------*

void cPtr_attrs::
method_string (C_Compiler & /* _inLexique */,
                                GGS_string& var_cas_s COMMA_UNUSED_LOCATION_ARGS) const {
  var_cas_s = GGS_string (true, "") ;
}

//---------------------------------------------------------------------------*

void cPtr_attrs::
appendForDescription (C_Compiler & _inLexique,
                      C_String & ioString,
                      const sint32 inIndentation
                      COMMA_LOCATION_ARGS) const {
  ioString << "->@attrs:"
           << location.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << attrs.reader_description  (_inLexique COMMA_THERE, inIndentation + 1) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                              Class message                                *
//                                                                           *
//---------------------------------------------------------------------------*

const char * cPtr_attrs::
_message (void) const {
  return "" ;
}

//---------------------------------------------------------------------------*

const char * cPtr_attrs::
_static_message (void) {
  return "" ;
}

//---------------------------------------------------------------------------*

C_galgas_class_inspector _gInspectorFor_attrs (& typeid (cPtr_attrs), & typeid (cPtr_basic_type), "") ;
//---------------------------------------------------------------------------*

AC_galgasClassRunTimeInformation * cPtr_attrs::galgasRTTI (void) const {
  return & gClassInfoFor__attrs ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                         GALGAS class 'GGS_attrs'                          *
//                                                                           *
//---------------------------------------------------------------------------*

GGS_attrs::
GGS_attrs (cPtr__AC_galgas_class * inPointer) {
  macroAssignPointer (mPointer, inPointer) ;
}

//---------------------------------------------------------------------------*

GGS_attrs::
GGS_attrs (cPtr__AC_galgas_class & inObject) {
  macroAssignPointer (mPointer, & inObject) ;
}

//---------------------------------------------------------------------------*

//--- _castFrom class method (implements cast expression)
GGS_attrs GGS_attrs::
_castFrom (C_Compiler & inLexique,
           cPtr__AC_galgas_class * inPointer,
           const bool inUseKindOfClass,
           const GGS_location & inErrorLocation
           COMMA_LOCATION_ARGS) {
  GGS_attrs _result ;
  if (inPointer != NULL) {
    macroValidPointer (inPointer) ;
    const bool ok = inUseKindOfClass
      ? (dynamic_cast <cPtr_attrs *> (inPointer) != NULL)
      : (typeid (cPtr_attrs) == typeid (*inPointer)) ;
    if (ok) {
      _result = GGS_attrs (inPointer) ;
    }else{
      inErrorLocation.signalCastError (inLexique,
                                       & typeid (cPtr_attrs),
                                       inUseKindOfClass,
                                       inPointer->_message ()
                                       COMMA_THERE) ;
    }
  }
  return _result ;
}

//---------------------------------------------------------------------------*

GGS_attrs GGS_attrs::
constructor_new (C_Compiler & /* inLexique */,
                 const GGS_location & argument_0,
                 const GGS_cfg_attrs & argument_1
                                COMMA_LOCATION_ARGS) {
  GGS_attrs result ;
  macroMyNew (result.mPointer, cPtr_attrs (argument_0,
                                argument_1 COMMA_THERE)) ;
  return result ;
}

//---------------------------------------------------------------------------*

GGS_cfg_attrs  GGS_attrs::
reader_attrs (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_cfg_attrs   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_attrs *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_attrs *) mPointer)->attrs ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

const char * GGS_attrs::actualTypeName (void) const {
  return "attrs" ;
}

//---------------------------------------------------------------------------*

C_galgasClassRunTimeInformation gClassInfoFor__attrs ("attrs", gClassInfoFor__basic_type) ;

//---------------------------------------------------------------------------*
