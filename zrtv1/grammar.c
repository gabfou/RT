/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:18:47 by ibuchwal          #+#    #+#             */
/*   Updated: 2016/02/25 21:19:03 by ibuchwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
**	properties		:=	WORD [COMMA properties]?
*/
