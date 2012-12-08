#pragma once

#include "Parser/PEParserCommon.h"
#include "Parser/DataLoader.h"
#include "PE/PEFile.h"

LIBPE_NAMESPACE_BEGIN

template <class T>
class PEElementT :
    public IPEElementT<T>
{
public:
    PEElementT()
        : m_pFile(NULL), m_nRVA(0), m_nVA(0), m_nSizeInMemory(0), m_nFOA(0), m_nSizeInFile(0)
    {}

    virtual ~PEElementT() {}

    void SetPEFile(PEFileT<T> *pFile) { m_pFile = pFile; }
    void SetParser(PEParserT<T> *pParser) { m_pParser = pParser; }
    void SetRVA(LibPEAddressT(T) nRVA) { m_nRVA = nRVA; }
    void SetVA(LibPEAddressT(T) nVA) { m_nVA = nVA; }
    void SetSizeInMemory(LibPEAddressT(T) nSizeInMemory) { m_nSizeInMemory = nSizeInMemory; }
    void SetFOA(LibPEAddressT(T) nFOA) { m_nFOA = nFOA; }
    void SetSizeInFile(LibPEAddressT(T) nSizeInFile) { m_nSizeInFile = nSizeInFile; }

    // Override IPEElementT<T>
    virtual void * LIBPE_CALLTYPE GetRawMemory();
    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetRawAddress();
    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetRawSize();

    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetRVA() { return m_nRVA; }
    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetVA();
    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetSizeInMemory() { return m_nSizeInMemory; }

    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetFOA();
    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetSizeInFile() { return m_nSizeInFile; }

protected:
    LibPEPtr<PEParserT<T>>  m_pParser;
    PEFileT<T>              *m_pFile;
    LibPEAddressT(T)        m_nRVA;
    LibPEAddressT(T)        m_nVA;
    LibPEAddressT(T)        m_nSizeInMemory;
    LibPEAddressT(T)        m_nFOA;
    LibPEAddressT(T)        m_nSizeInFile;
};

typedef PEElementT<PE32> PEElement32;
typedef PEElementT<PE64> PEElement64;

#define DECLARE_PE_ELEMENT(struct_type)     \
    virtual void * LIBPE_CALLTYPE GetRawMemory() { return PEElementT<T>::GetRawMemory(); }                  \
    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetRawAddress() { return PEElementT<T>::GetRawAddress(); }      \
    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetRawSize() { return PEElementT<T>::GetRawSize(); }            \
    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetRVA() { return PEElementT<T>::GetRVA(); }                    \
    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetVA() { return PEElementT<T>::GetVA(); }                      \
    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetSizeInMemory() { return PEElementT<T>::GetSizeInMemory(); }  \
    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetFOA() { return PEElementT<T>::GetFOA(); }                    \
    virtual LibPEAddressT(T) LIBPE_CALLTYPE GetSizeInFile(){ return PEElementT<T>::GetSizeInFile(); }       \
    virtual struct_type * LIBPE_CALLTYPE GetRawStruct() { return (struct_type *)PEElementT<T>::GetRawMemory(); }

LIBPE_NAMESPACE_END