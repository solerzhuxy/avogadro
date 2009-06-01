// Last update: timvdm 12 May 2009

#include <boost/python.hpp>

#include <avogadro/openbabelwrapper.h>
#include <avogadro/moleculefile.h>
#include <avogadro/molecule.h>

#include <QStringList>

using namespace boost::python;
using namespace Avogadro;

// handle default arguments
MoleculeFile* readFile1(const QString &fileName) 
{ return OpenbabelWrapper::readFile(fileName); }
MoleculeFile* readFile2(const QString &fileName, const QString &fileType) 
{ return OpenbabelWrapper::readFile(fileName, fileType); }
MoleculeFile* readFile3(const QString &fileName, const QString &fileType, const QString &fileOptions) 
{ return OpenbabelWrapper::readFile(fileName, fileType, fileOptions); }

// readMolecule
Molecule* readMolecule1(const QString &fileName) 
{ return OpenbabelWrapper::readMolecule(fileName); }
Molecule* readMolecule2(const QString &fileName, const QString &fileType) 
{ return OpenbabelWrapper::readMolecule(fileName, fileType); }
Molecule* readMolecule3(const QString &fileName, const QString &fileType, const QString &fileOptions) 
{ return OpenbabelWrapper::readMolecule(fileName, fileType, fileOptions); }
Molecule* readMolecule4(const QString &fileName, const QString &fileType, const QString &fileOptions, QString *error)
{ return OpenbabelWrapper::readMolecule(fileName, fileType, fileOptions, error); }

// writeMolecule
bool writeMolecule1(Molecule *molecule, const QString &fileName) 
{ return OpenbabelWrapper::writeMolecule(molecule, fileName); }
bool writeMolecule2(Molecule *molecule, const QString &fileName, const QString &fileType) 
{ return OpenbabelWrapper::writeMolecule(molecule, fileName, fileType); }
bool writeMolecule3(Molecule *molecule, const QString &fileName, const QString &fileType, QString *error) 
{ return OpenbabelWrapper::writeMolecule(molecule, fileName, fileType, error); }

// WriteConformers
bool writeConformers1(Molecule *molecule, const QString &fileName) 
{ return OpenbabelWrapper::writeConformers(molecule, fileName); }
bool writeConformers2(Molecule *molecule, const QString &fileName, const QString &fileType) 
{ return OpenbabelWrapper::writeConformers(molecule, fileName, fileType); }
bool writeConformers3(Molecule *molecule, const QString &fileName, const QString &fileType, QString *error) 
{ return OpenbabelWrapper::writeConformers(molecule, fileName, fileType, error); }



void export_FileIO()
{
  QList<QString> (MoleculeFile::*titles_ptr)() const = &MoleculeFile::titles;

  class_<Avogadro::MoleculeFile, boost::noncopyable>("MoleculeFile", no_init)
    .add_property("isConformerFile", &MoleculeFile::isConformerFile)
    .add_property("numMolecules", &MoleculeFile::numMolecules)
    .add_property("titles", titles_ptr)
//    .add_property("conformers", &MoleculeFile::conformers)
    .def("molecule", &MoleculeFile::molecule, return_value_policy<manage_new_object>())
    ;
  
  class_<Avogadro::OpenbabelWrapper, boost::noncopyable>("OpenbabelWrapper", no_init)
    .def("readMolecule", &readMolecule1, return_value_policy<manage_new_object>())
    .def("readMolecule", &readMolecule2, return_value_policy<manage_new_object>())
    .def("readMolecule", &readMolecule3, return_value_policy<manage_new_object>())
    .def("readMolecule", &readMolecule4, return_value_policy<manage_new_object>())
    .staticmethod("readMolecule")
    .def("writeMolecule", &writeMolecule1)
    .def("writeMolecule", &writeMolecule2)
    .def("writeMolecule", &writeMolecule3)
    .staticmethod("writeMolecule")
    .def("writeConformers", &writeConformers1)
    .def("writeConformers", &writeConformers2)
    .def("writeConformers", &writeConformers3)
    .staticmethod("writeConformers")
    .def("readFile", &OpenbabelWrapper::readFile, return_value_policy<manage_new_object>())
    .def("readFile", &readFile1, return_value_policy<manage_new_object>())
    .def("readFile", &readFile2, return_value_policy<manage_new_object>())
    .def("readFile", &readFile3, return_value_policy<manage_new_object>())
    .staticmethod("readFile")
    ;













}