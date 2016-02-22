/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 19:15:29 by ibuchwal          #+#    #+#             */
/*   Updated: 2014/03/13 23:15:31 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	GRAMMAR :
**
**	exp				:=	scene object
**
**	scene			:=	camera window
**
**	object			:=	[light]* [shape]*
**
**	shape			:=	WORD OPENING_BRACKET properties CLOSING_BRACKET
**
**	light			:=	WORD OPENING_BRACKET properties CLOSING_BRACKET
**
**	camera			:=	WORD OPENING_BRACKET properties CLOSING_BRACKET
**
**	window			:=	WORD OPENING_BRACKET properties CLOSING_BRACKET
**
**	properties		:=	WORD COLON WORD [COMMA properties]?
*/
