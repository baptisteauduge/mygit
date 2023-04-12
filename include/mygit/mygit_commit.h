// MyGit Project
//
// mygit_commit.h
// File description:
//    mygit_commit.h

#ifndef MYGIT_COMMIT_H
#define MYGIT_COMMIT_H

#define COMMIT_PARENT_KEY "predecessor"
#define COMMIT_MESSAGE_KEY "message"

char *mygit_commit(const char *branch_name, const char *message);

#endif
