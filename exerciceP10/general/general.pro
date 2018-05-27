TEMPLATE = subdirs

SUBDIRS +=  \
            # chariot \ # n'est plus fonctionnel
            # eulercromer \ # n'est plus fonctionnel
            # newmark \ # n'est plus fonctionnel
            # oscillateur \ # n'est plus fonctionnel
            # pendule \ # n'est plus fonctionnel
            phase \
            # ressort \ # n'est plus fonctionnel
            # rungekutta \ # n'est plus fonctionnel
            # systeme \ # n'est plus fonctionnel
            # torsion \ # n'est plus fonctionnel
            vecteur \
            # ../text/testtextviewer.pro \ # n'est plus fonctionnel

# on écrit un message pour préciser ce qui est fonctionnel.
message(" ")
message(" ")
message(" ")
message(" ")
message(" ")
message(" ")
message(" ===================================== ")
message(" Fichiers de test qui sont fonctionnels: ")
message("    "$$SUBDIRS)
message(" ===================================== ")
message(" ")
message(" ")
message(" ")
message(" ")
message(" ")
message(" ")
