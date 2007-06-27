/* bzflag
 * Copyright (c) 1993 - 2007 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * Remote Control Link, Backend: Encapsulates communication between backend and
 * frontend, from the backends point of view.
 */

#ifndef	BZF_RC_LINK_BACKEND_H
#define	BZF_RC_LINK_BACKEND_H

#include "RCLink.h"
#include "RCRequest.h"

class RCLinkBackend : public RCLink
{
  private:
    RCRequest *requests;

  public:
    RCLinkBackend(int port);
    int update_read();
    int update_parse(int maxlines = 0);
    void update();
    bool parsecommand(char *cmdline);
    RCRequest* poprequest();
    RCRequest* peekrequest();
};

#endif

// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8
