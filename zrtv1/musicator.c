/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   musicator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfournie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 23:20:18 by gfournie          #+#    #+#             */
/*   Updated: 2016/03/17 23:20:21 by gfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
// 0x00000040

void	addmusic(t_leviatenv *levia, char *name)
{
	t_lm	*new;

	if (!levia)
		ft_error("addmusic no levia");
	new = malloc(sizeof(t_lm));
	new->name = name;
	new->previous = NULL;
	new->next = NULL;
	if (!(levia->fmod.listmusic))
		levia->fmod.listmusic = new;
	else if (!(levia->fmod.listmusic->previous))
	{
		new->next = levia->fmod.listmusic;
		new->previous = levia->fmod.listmusic;
		levia->fmod.listmusic->previous = new;
		levia->fmod.listmusic->next = new;

	}
	else
	{
		new->next = levia->fmod.listmusic;
		new->previous = levia->fmod.listmusic->previous;
		levia->fmod.listmusic->previous->next = new;
		levia->fmod.listmusic->previous = new;
	}
}

void	initfmod(t_leviatenv *levia)
{
	levia->fmod.handle = dlopen("./fmod/lib/libfmod.dylib", RTLD_LAZY);
	levia->fmod.Sound_SetLoopCount =
	dlsym(levia->fmod.handle, "FMOD_Sound_SetLoopCount");
	levia->fmod.System_Init =
	dlsym(levia->fmod.handle, "FMOD_System_Init");
	levia->fmod.System_CreateSound =
	dlsym(levia->fmod.handle, "FMOD_System_CreateSound");
	levia->fmod.System_Create =
	dlsym(levia->fmod.handle, "FMOD_System_Create");
	levia->fmod.System_PlaySound =
	dlsym(levia->fmod.handle, "FMOD_System_PlaySound");
	levia->fmod.listmusic = NULL;
	addmusic(levia, "airwolf2.mp3");
	addmusic(levia, "metalman.mp3");
	addmusic(levia, "libera.mp3");
	addmusic(levia, "spellforcelianon.mp3");
	addmusic(levia, "drwillystage2.mp3");
	addmusic(levia, "spellforcerunewarrior.mp3");
	addmusic(levia, "FF1chaostemple.mp3");
	addmusic(levia, "spellforceelfvillage.mp3");
}

void	*printmusicator(t_limg *limg, t_env *env)
{
	int i;
	int j;
	int k;

	(void)k;
	(void)env;
	if (limg)
	{
		k = 0;
		j = 300;
		while (++j < 350)
		{
			i = 200 - k;
			while (--i > 150 + k)
				pixel_to_image(j, i, 0x2E7AE8 , limg);
			k++;
		}
		j = 100;
		k = 0;
		while (++j < 150)
		{
			i = 200 - k;
			while (++i < 150 + k)
				pixel_to_image(j, i, 0x2E7AE8 , limg);
			k++;
		}
	}
	return (NULL);
}

void	nextrack(t_leviatenv *levia, int sens, char *son)
{
	static FMOD_SYSTEM	*fmod = NULL;
	static FMOD_SOUND	*sound;
	// FMOD_RESULT			resultat;

	if (fmod == NULL)
	{
		levia->fmod.System_Create(&fmod);
		levia->fmod.System_Init(fmod, 1, FMOD_INIT_NORMAL, NULL);
		ft_putendl("niark");
	}
	if (son != NULL)
	{
		levia->fmod.System_CreateSound(fmod, son,
			FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &sound);
		levia->fmod.Sound_SetLoopCount(sound, -1);
		levia->fmod.System_PlaySound(fmod, sound, NULL, 0, NULL);
		return ;
	}
	(void)levia;
	if (sens && levia->fmod.listmusic)
	{
		if (levia->fmod.listmusic->next)
			levia->fmod.listmusic = levia->fmod.listmusic->next;
		levia->fmod.System_CreateSound(fmod, levia->fmod.listmusic->name,
			FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &sound);
		levia->fmod.Sound_SetLoopCount(sound, -1);
		levia->fmod.System_PlaySound(fmod, sound, NULL, 0, NULL);
	}
	else if (levia->fmod.listmusic)
	{
		if (levia->fmod.listmusic->previous)
			levia->fmod.listmusic = levia->fmod.listmusic->previous;
		levia->fmod.System_CreateSound(fmod, levia->fmod.listmusic->name,
			FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &sound);
		levia->fmod.Sound_SetLoopCount(sound, -1);
		levia->fmod.System_PlaySound(fmod, sound, NULL, 0, NULL);
	}
}
