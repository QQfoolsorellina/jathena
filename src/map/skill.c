/* �X�L���֌W */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "timer.h"

#include "skill.h"
#include "map.h"
#include "clif.h"
#include "pc.h"
#include "pet.h"
#include "mob.h"
#include "battle.h"
#include "party.h"
#include "itemdb.h"
#include "script.h"

#define SKILLUNITTIMER_INVERVAL	100

/* �X�L���ԍ������X�e�[�^�X�ُ�ԍ��ϊ��e�[�u�� */
int SkillStatusChangeTable[]={	/* skill.h��enum��SC_***�Ƃ��킹�邱�� */
/* 0- */
	-1,-1,-1,-1,-1,-1,
	SC_PROVOKE,			/* �v���{�b�N */
	-1, 1,-1,
/* 10- */
	SC_SIGHT,			/* �T�C�g */
	-1,-1,-1,-1,
	SC_FREEZE,			/* �t���X�g�_�C�o�[ */
	SC_STONE,			/* �X�g�[���J�[�X */
	-1,-1,-1,
/* 20- */
	-1,-1,-1,-1,
	SC_RUWACH,			/* ���A�t */
	-1,-1,-1,-1,
	SC_INCREASEAGI,		/* ���x���� */
/* 30- */
	SC_DECREASEAGI,		/* ���x���� */
	-1,
	SC_SIGNUMCRUCIS,	/* �V�O�i���N���V�X */
	SC_ANGELUS,			/* �G���W�F���X */
	SC_BLESSING,		/* �u���b�V���O */
	-1,-1,-1,-1,-1,
/* 40- */
	-1,-1,-1,-1,-1,
	SC_CONCENTRATE,		/* �W���͌��� */
	-1,-1,-1,-1,
/* 50- */
	-1,
	SC_HIDING,			/* �n�C�f�B���O */
	-1,-1,-1,-1,-1,-1,-1,-1,
/* 60- */
	SC_TWOHANDQUICKEN,	/* 2HQ */
	SC_AUTOCOUNTER,
	-1,-1,-1,-1,
	SC_IMPOSITIO,		/* �C���|�V�e�B�I�}�k�X */
	SC_SUFFRAGIUM,		/* �T�t���M�E�� */
	SC_ASPERSIO,		/* �A�X�y���V�I */
	SC_BENEDICTIO,		/* ���̍~�� */
/* 70- */
	-1,
	SC_SLOWPOISON,
	-1,
	SC_KYRIE,			/* �L���G�G���C�\�� */
	SC_MAGNIFICAT,		/* �}�O�j�t�B�J�[�g */
	SC_GLORIA,			/* �O�����A */
	SC_DIVINA,			/* ���b�N�X�f�B�r�[�i */
	-1,
	SC_AETERNA,			/* ���b�N�X�G�[�e���i */
	-1,
/* 80- */
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
/* 90- */
	-1,-1,
	SC_QUAGMIRE,		/* �N�@�O�}�C�A */
	-1,-1,-1,-1,-1,-1,-1,
/* 100- */
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
/* 110- */
	-1,
	SC_ADRENALINE,		/* �A�h���i�������b�V�� */
	SC_WEAPONPERFECTION,/* �E�F�|���p�[�t�F�N�V���� */
	SC_OVERTHRUST,		/* �I�[�o�[�g���X�g */
	SC_MAXIMIZEPOWER,	/* �}�L�V�}�C�Y�p���[ */
	-1,-1,-1,-1,-1,
/* 120- */
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
/* 130- */
	-1,-1,-1,-1,-1,
	SC_CLOAKING,		/* �N���[�L���O */
	SC_STAN,			/* �\�j�b�N�u���[ */
	-1,
	SC_ENCPOISON,		/* �G���`�����g�|�C�Y�� */
	SC_POISONREACT,		/* �|�C�Y�����A�N�g */
/* 140- */
	SC_POISON,			/* �x�m���_�X�g */
	-1,-1,
	SC_TRICKDEAD,		/* ���񂾂ӂ� */
	-1,-1,-1,-1,-1,-1,
/* 150- */
	-1,-1,-1,-1,-1,
	SC_LOUD,			/* ���E�h�{�C�X */
	-1,
	SC_ENERGYCOAT,		/* �G�i�W�[�R�[�g */
	-1,-1,
/* 160- */
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	-1,
	SC_KEEPING,
	-1,-1,
	SC_BARRIER,
	-1,-1,
	SC_HALLUCINATION,
	-1,-1,
/* 210- */
	-1,-1,-1,-1,-1,
	SC_STRIPWEAPON,
	SC_STRIPSHIELD,
	SC_STRIPARMOR,
	SC_STRIPHELM,
	-1,
/* 220- */
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
/* 230- */
	-1,-1,-1,-1,
	SC_CP_WEAPON,
	SC_CP_SHIELD,
	SC_CP_ARMOR,
	SC_CP_HELM,
	-1,-1,
/* 240- */
	-1,-1,-1,-1,-1,-1,-1,-1,-1,
	SC_AUTOGUARD,
/* 250- */
	-1,-1,
	SC_REFLECTSHIELD,
	-1,-1,
	SC_DEVOTION,
	SC_PROVIDENCE,
	SC_DEFENDER,
	SC_SPEARSQUICKEN,
	-1,
/* 260- */
	-1,-1,-1,-1,-1,-1,-1,-1,
	SC_STEELBODY,
	SC_BLADESTOP_WAIT,
/* 270- */
	SC_EXPLOSIONSPIRITS,
	-1,-1,-1,-1,-1,
	SC_MAGICROD,
	-1,-1,-1,
/* 280- */
	SC_FLAMELAUNCHER,
	SC_FROSTWEAPON,
	SC_LIGHTNINGLOADER,
	SC_SEISMICWEAPON,
	-1,
	SC_VOLCANO,
	SC_DELUGE,
	SC_VIOLENTGALE,
	-1,-1,
/* 290- */
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
/* 300- */
	-1,-1,-1,-1,-1,-1,
	SC_LULLABY,
	SC_RICHMANKIM,
	SC_ETERNALCHAOS,
	SC_DRUMBATTLE,
/* 310- */
	SC_NIBELUNGEN,
	SC_ROKISWEIL,
	SC_INTOABYSS,
	SC_SIEGFRIED,
	-1,-1,-1,
	SC_DISSONANCE,
	-1,
	SC_WHISTLE,
/* 320- */
	SC_ASSNCROS,
	SC_POEMBRAGI,
	SC_APPLEIDUN,
	-1,-1,
	SC_UGLYDANCE,
	-1,
	SC_HUMMING,
	SC_DONTFORGETME,
	SC_FORTUNE,
/* 330- */
	SC_SERVICE4U,
	-1,-1,-1,-1,-1,-1,-1,-1,-1,
};

static const int dirx[8]={0,-1,-1,-1,0,1,1,1};
static const int diry[8]={1,1,0,-1,-1,-1,0,1};

static int rdamage;

/* �X�L���f�[�^�x�[�X */
struct skill_db skill_db[MAX_SKILL_DB];

/* �A�C�e���쐬�f�[�^�x�[�X */
struct skill_produce_db skill_produce_db[MAX_SKILL_PRODUCE_DB];

/* ��쐬�X�L���f�[�^�x�[�X */
struct skill_arrow_db skill_arrow_db[MAX_SKILL_ARROW_DB];

/* �A�u���J�_�u�������X�L���f�[�^�x�[�X */
struct skill_abra_db skill_abra_db[MAX_SKILL_ABRA_DB];

int	skill_get_hit( int id ){ return skill_db[id].hit; }
int	skill_get_inf( int id ){ return skill_db[id].inf; }
int	skill_get_pl( int id ){ return skill_db[id].pl; }
int	skill_get_nk( int id ){ return skill_db[id].nk; }
int	skill_get_max( int id ){ return skill_db[id].max; }
int skill_get_range( int id , int lv ){ return (lv <= 0) ? 0:skill_db[id].range[lv-1]; }
int	skill_get_hp( int id ,int lv ){ return (lv <= 0) ? 0:skill_db[id].hp[lv-1]; }
int	skill_get_sp( int id ,int lv ){ return (lv <= 0) ? 0:skill_db[id].sp[lv-1]; }
int	skill_get_zeny( int id ,int lv ){ return (lv <= 0) ? 0:skill_db[id].zeny[lv-1]; }
int	skill_get_num( int id ,int lv ){ return (lv <= 0) ? 0:skill_db[id].num[lv-1]; }
int	skill_get_cast( int id ,int lv ){ return (lv <= 0) ? 0:skill_db[id].cast[lv-1]; }
int	skill_get_delay( int id ,int lv ){ return (lv <= 0) ? 0:skill_db[id].delay[lv-1]; }
int	skill_get_time( int id ,int lv ){ return (lv <= 0) ? 0:skill_db[id].upkeep_time[lv-1]; }
int	skill_get_time2( int id ,int lv ){ return (lv <= 0) ? 0:skill_db[id].upkeep_time2[lv-1]; }
int	skill_get_castdef( int id ){ return skill_db[id].cast_def_rate; }
int	skill_get_weapontype( int id ){ return skill_db[id].weapon; }
int	skill_get_inf2( int id ){ return skill_db[id].inf2; }
int	skill_get_maxcount( int id ){ return skill_db[id].maxcount; }
int	skill_get_blewcount( int id ,int lv ){ return (lv <= 0) ? 0:skill_db[id].blewcount[lv-1]; }


/* �v���g�^�C�v */
struct skill_unit_group *skill_unitsetting( struct block_list *src, int skillid,int skilllv,int x,int y,int flag);
int skill_check_condition( struct map_session_data *sd,int type);
int skill_castend_damage_id( struct block_list* src, struct block_list *bl,int skillid,int skilllv,unsigned int tick,int flag );
int skill_frostjoke_scream(struct block_list *bl,va_list ap);
int skill_status_change_timer_sub(struct block_list *bl, va_list ap );
int skill_attack_area(struct block_list *bl,va_list ap);
int skill_is_danceskill(int id);
int skill_abra_dataset(int skilllv);
int skill_clear_element_field(struct block_list *bl);
int skill_landprotector(struct block_list *bl, va_list ap );

static int distance(int x0,int y0,int x1,int y1)
{
	int dx,dy;

	dx=abs(x0-x1);
	dy=abs(y0-y1);
	return dx>dy ? dx : dy;
}

/* �X�L�����j�b�gID��Ԃ��i������f�[�^�x�[�X�ɓ��ꂽ���ȁj */
int skill_get_unit_id(int id,int flag)
{
	switch(id){
	case MG_SAFETYWALL:		return 0x7e;				/* �Z�C�t�e�B�E�H�[�� */
	case MG_FIREWALL:		return 0x7f;				/* �t�@�C�A�[�E�H�[�� */
	case AL_WARP:			return (flag==0)?0x81:0x80;	/* ���[�v�|�[�^�� */
	case PR_BENEDICTIO:		return 0x82;				/* ���̍~�� */
	case PR_SANCTUARY:		return 0x83;				/* �T���N�`���A�� */
	case PR_MAGNUS:			return 0x84;				/* �}�O�k�X�G�N�\�V�Y�� */
	case AL_PNEUMA:			return 0x85;				/* �j���[�} */
	case MG_THUNDERSTORM:	return 0x86;		/* �T���_�[�X�g�[�� */
	case WZ_HEAVENDRIVE:	return 0x86;		/* �w�����Y�h���C�u */
	case WZ_SIGHTRASHER:	return 0x86;
	case WZ_METEOR:			return 0x86;				/* ���e�I�X�g�[�� */
	case WZ_VERMILION:		return 0x86;				/* ���[�h�I�u���@�[�~���I�� */
	case WZ_FROSTNOVA:		return 0x86;			/* �t���X�g�m���@ */
	case WZ_STORMGUST:		return 0x86;				/* �X�g�[���K�X�g(�Ƃ肠����LoV�Ɠ����ŏ���) */
	case CR_GRANDCROSS:		return 0x86;				/* �O�����h�N���X */
	case WZ_FIREPILLAR:		return (flag==0)?0x87:0x88;	/* �t�@�C�A�[�s���[ */
	case HT_TALKIEBOX:		return 0x99;	/* �g�[�L�[�{�b�N�X */
	case WZ_ICEWALL:		return 0x8d;				/* �A�C�X�E�H�[�� */
	case WZ_QUAGMIRE:		return 0x8e;				/* �N�@�O�}�C�A */
	case HT_BLASTMINE:		return 0x8f;				/* �u���X�g�}�C�� */
	case HT_SKIDTRAP:		return 0x90;				/* �X�L�b�h�g���b�v */
	case HT_ANKLESNARE:		return 0x91;				/* �A���N���X�l�A */
	case AS_VENOMDUST:		return 0x92;				/* �x�m���_�X�g */
	case HT_LANDMINE:		return 0x93;				/* �����h�}�C�� */
	case HT_SHOCKWAVE:		return 0x94;				/* �V���b�N�E�F�[�u�g���b�v */
	case HT_SANDMAN:		return 0x95;				/* �T���h�}�� */
	case HT_FLASHER:		return 0x96;				/* �t���b�V���[ */
	case HT_FREEZINGTRAP:	return 0x97;				/* �t���[�W���O�g���b�v */
	case HT_CLAYMORETRAP:	return 0x98;				/* �N���C���A�[�g���b�v */
	case SA_VOLCANO:	return 0x9a;					/* �{���P�[�m */
	case SA_DELUGE:			return 0x9b;				/* �f�����[�W */
	case SA_VIOLENTGALE:	return 0x9c;					/* �o�C�I�����g�Q�C�� */
	case SA_LANDPROTECTOR:	return 0x9d;					/* �����h�v���e�N�^�[ */
	case BD_LULLABY:		return 0x9e;				/* �q��� */
	case BD_RICHMANKIM:		return 0x9f;				/* �j�����h�̉� */
	case BD_ETERNALCHAOS:	return 0xa0;				/* �i���̍��� */
	case BD_DRUMBATTLEFIELD:return 0xa1;					/* �푾�ۂ̋��� */
	case BD_RINGNIBELUNGEN:	return 0xa2;				/* �j�[�x�����O�̎w�� */
	case BD_ROKISWEIL:		return 0xa3;				/* ���L�̋��� */
	case BD_INTOABYSS:		return 0xa4;				/* �[���̒��� */
	case BD_SIEGFRIED:		return 0xa5;				/* �s���g�̃W�[�N�t���[�h */
	case BA_DISSONANCE:		return 0xa6;				/* �s���a�� */
	case BA_WHISTLE:		return 0xa7;				/* ���J */
	case BA_ASSASSINCROSS:	return 0xa8;				/* �[�z�̃A�T�V���N���X */
	case BA_POEMBRAGI:		return 0xa9;				/* �u���M�̎� */
	case BA_APPLEIDUN:		return 0xaa;				/* �C�h�D���̗ь� */
	case DC_UGLYDANCE:		return 0xab;				/* ��������ȃ_���X */
	case DC_HUMMING:		return 0xac;				/* �n�~���O */
	case DC_DONTFORGETME:	return 0xad;				/* ����Y��Ȃ��Łc */
	case DC_FORTUNEKISS:	return 0xae;				/* �K�^�̃L�X */
	case DC_SERVICEFORYOU:	return 0xaf;				/* �T�[�r�X�t�H�[���[ */
	case RG_GRAFFITI:		return 0xb0;				/* �O���t�B�e�B */
	case AM_DEMONSTRATION:		return 0xb1;				/* �f�����X�g���[�V���� */
	}
	return 0;
	/*
	0x89,0x8a,0x8b �\������
	0x9a �������̉r���݂����ȃG�t�F�N�g
	0x9b �������̉r���݂����ȃG�t�F�N�g
	0x9c �������̉r���݂����ȃG�t�F�N�g
	0x9d ���������ȃG�t�F�N�g
	*/
}

/*==========================================
 * �X�L���ǉ�����
 *------------------------------------------
 */
int skill_additional_effect( struct block_list* src, struct block_list *bl,int skillid,int skilllv,int attack_type,unsigned int tick)
{
	/* MOB�ǉ����ʃX�L���p */
	const int sc[]={
		SC_POISON, SC_BLIND, SC_SILENCE, SC_STAN,
		SC_STONE, SC_CURSE, SC_SLEEP
	};
	const int sc2[]={
		MG_STONECURSE,MG_FROSTDIVER,NPC_STUNATTACK,
		NPC_SLEEPATTACK,TF_POISON,NPC_CURSEATTACK,
		NPC_SILENCEATTACK,0,NPC_BLINDATTACK
	};

	struct map_session_data *sd=NULL;
	struct map_session_data *dstsd=NULL;
	struct mob_data *md=NULL;
	struct mob_data *dstmd=NULL;

	int skill,skill2;
	int rate,luk;

	int sc_def_mdef,sc_def_vit,sc_def_int,sc_def_luk;

	if(skilllv < 0) return 0;

	if(src->type==BL_PC)
		sd=(struct map_session_data *)src;
	else if(src->type==BL_MOB)
		md=(struct mob_data *)src;

	luk = battle_get_luk(bl);
	sc_def_mdef=100 - (3 + battle_get_mdef(bl) + luk/3);
	sc_def_vit=100 - (3 + battle_get_vit(bl) + luk/3);
	sc_def_int=100 - (3 + battle_get_int(bl) + luk/3);
	sc_def_luk=100 - (3 + luk);
	if(bl->type==BL_PC)
		dstsd=(struct map_session_data *)bl;
	else if(bl->type==BL_MOB){
		dstmd=(struct mob_data *)bl;
		if(sc_def_mdef>50)
			sc_def_mdef=50;
		if(sc_def_vit>50)
			sc_def_vit=50;
		if(sc_def_int>50)
			sc_def_int=50;
		if(sc_def_luk>50)
			sc_def_luk=50;
	}
	if(sc_def_mdef<0)
		sc_def_mdef=0;
	if(sc_def_vit<0)
		sc_def_vit=0;
	if(sc_def_int<0)
		sc_def_int=0;

	switch(skillid){
	case 0:					/* �ʏ�U�� */
		/* ������ */
		if( sd && pc_isfalcon(sd) && sd->status.weapon == 11 && (skill=pc_checkskill(sd,HT_BLITZBEAT))>0 &&
			rand()%1000 <= sd->paramc[5]*10/3+1 ) {
			int lv=(sd->status.job_level+9)/10;
			skill_castend_damage_id(src,bl,HT_BLITZBEAT,(skill<lv)?skill:lv,tick,0xf00000);
		}
		// �X�i�b�`���[
		if(sd && sd->status.weapon != 11 && (skill=pc_checkskill(sd,RG_SNATCHER)) > 0)
			if((skill*15 + 55) + (skill2 = pc_checkskill(sd,TF_STEAL))*10 > rand()%1000)
				if(pc_steal_item(sd,bl))
					clif_skill_nodamage(src,bl,TF_STEAL,skill2,1);
		break;

	case SM_BASH:			/* �o�b�V���i�}���U���j */
		if( sd && (skill=pc_checkskill(sd,SM_FATALBLOW))>0 ){
			if( rand()%100 < 6*(skilllv-5)*sc_def_vit/100 )
				skill_status_change_start(bl,SC_STAN,skilllv,0,0,0,skill_get_time2(SM_FATALBLOW,skilllv),0);
		}
		break;

	case TF_POISON:			/* �C���x�i�� */
		if(rand()%100< (2*skilllv+10)*sc_def_vit/100 )
			skill_status_change_start(bl,SC_POISON,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;

	case AS_SONICBLOW:		/* �\�j�b�N�u���[ */
		if( rand()%100 < (2*skilllv+10)*sc_def_vit/100 )
			skill_status_change_start(bl,SC_STAN,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;


	case HT_FREEZINGTRAP:	/* �t���[�W���O�g���b�v */
		rate=skilllv*3+35;
		if(rand()%100 < rate*sc_def_mdef/100)
			skill_status_change_start(bl,SC_FREEZE,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;

	case MG_FROSTDIVER:		/* �t���X�g�_�C�o�[ */
	case WZ_FROSTNOVA:		/* �t���X�g�m���@ */
		rate=(skilllv*3+35)*sc_def_mdef/100-(battle_get_int(bl)+battle_get_luk(bl))/15;
		rate=rate<=5?5:rate;
		if(rand()%100 < rate)
			skill_status_change_start(bl,SC_FREEZE,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		else if(sd)
			clif_skill_fail(sd,skillid,0,0);
		break;

	case WZ_STORMGUST:		/* �X�g�[���K�X�g */
		{
			struct status_change *sc_data = battle_get_sc_data(bl);
			if(sc_data) {
				sc_data[SC_FREEZE].val3++;
				if(sc_data[SC_FREEZE].val3 >= 3)
					skill_status_change_start(bl,SC_FREEZE,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
			}
		}
		break;

	case HT_LANDMINE:		/* �����h�}�C�� */
		if( rand()%100 < (5*skilllv+30)*sc_def_vit/100 )
			skill_status_change_start(bl,SC_STAN,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;

	case HT_ANKLESNARE:		/* �A���N���X�l�A */
		{
			int sec=skill_get_time2(skillid,skilllv);
			if(battle_get_mode(bl)&0x20)
				sec = sec/5;
			battle_stopwalking(bl,1);
			skill_status_change_start(bl,SC_ANKLE,skilllv,0,0,0,sec,0);
		}
		break;

	case HT_SANDMAN:		/* �T���h�}�� */
		if( rand()%100 < (5*skilllv+30)*sc_def_int/100 )
			skill_status_change_start(bl,SC_SLEEP,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;

	case TF_SPRINKLESAND:	/* ���܂� */
		if( rand()%100 < 15*sc_def_int/100 )
			skill_status_change_start(bl,SC_BLIND,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;

	case TF_THROWSTONE:		/* �Γ��� */
		if( rand()%100 < 5*sc_def_vit/100 )
			skill_status_change_start(bl,SC_STAN,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;

	case CR_HOLYCROSS:		/* �z�[���[�N���X */
		if( rand()%100 < 3*skilllv*sc_def_int/100 )
			skill_status_change_start(bl,SC_BLIND,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;

	case CR_GRANDCROSS:		/* �O�����h�N���X */
		{
			int race = battle_get_race(bl);
			if( (battle_check_undead(race,battle_get_elem_type(bl)) || race == 6) && rand()%100 < sc_def_int)
				skill_status_change_start(bl,SC_BLIND,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		}
		break;

	case CR_SHIELDCHARGE:		/* �O�����h�N���X */
		if( rand()%100 < (15 + skilllv*5)*sc_def_vit/100 )
			skill_status_change_start(bl,SC_STAN,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;

	case RG_RAID:		/* �T�v���C�Y�A�^�b�N */
		if( rand()%100 < (10+3*skilllv)*sc_def_vit/100 )
			skill_status_change_start(bl,SC_STAN,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		if( rand()%100 < (10+3*skilllv)*sc_def_int/100 )
			skill_status_change_start(bl,SC_BLIND,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;
	case BA_FROSTJOKE:
		if(rand()%100 < (15+5*skilllv)*sc_def_mdef/100)
			skill_status_change_start(bl,SC_FREEZE,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;

	case DC_SCREAM:
		if( rand()%100 < (25+5*skilllv)*sc_def_vit/100 )
			skill_status_change_start(bl,SC_STAN,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;

	case BD_LULLABY:	/* �q��S */
		if( rand()%100 < 15*sc_def_int/100 )
			skill_status_change_start(bl,SC_SLEEP,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;

	/* MOB�̒ǉ����ʕt���X�L�� */

	case NPC_PETRIFYATTACK:
		if(rand()%100 < sc_def_mdef)
			skill_status_change_start(bl,sc[skillid-NPC_POISON],skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;
	case NPC_POISON:
	case NPC_SILENCEATTACK:
	case NPC_STUNATTACK:
		if(rand()%100 < sc_def_vit)
			skill_status_change_start(bl,sc[skillid-NPC_POISON],skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;
	case NPC_CURSEATTACK:
		if(rand()%100 < sc_def_luk)
			skill_status_change_start(bl,sc[skillid-NPC_POISON],skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;
	case NPC_SLEEPATTACK:
	case NPC_BLINDATTACK:
		if(rand()%100 < sc_def_int)
			skill_status_change_start(bl,sc[skillid-NPC_POISON],skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;
	case NPC_MENTALBREAKER:
		if(dstsd) {
			int sp = dstsd->status.max_sp*(10+skilllv)/100;
			if(sp < 1) sp = 1;
			pc_heal(dstsd,0,-sp);
		}
		break;
	}

	if(sd && skillid != MC_CARTREVOLUTION && attack_type&BF_WEAPON){	/* �J�[�h�ɂ��ǉ����� */
		int i;
		int sc_def_card=100;

		for(i=SC_STONE;i<=SC_BLIND;i++){
			if(i==SC_STONE || i==SC_FREEZE)
				sc_def_card=sc_def_mdef;
			else if(i==SC_STAN || i==SC_POISON || i==SC_SILENCE)
				sc_def_card=sc_def_vit;
			else if(i==SC_SLEEP || i==SC_CONFUSION || i==SC_BLIND)
				sc_def_card=sc_def_int;
			else if(i==SC_CURSE)
				sc_def_card=sc_def_luk;

			if(!sd->state.arrow_atk) {
				if(rand()%10000 < (sd->addeff[i-SC_STONE])*sc_def_card/100 ){
					if(battle_config.battle_log)
						printf("PC %d skill_addeff: card�ɂ��ُ픭�� %d %d\n",sd->bl.id,i,sd->addeff[i-SC_STONE]);
					skill_status_change_start(bl,i,7,0,0,0,(i==SC_CONFUSION)? 10000+7000:skill_get_time2(sc2[i-SC_STONE],7),0);
				}
			}
			else {
				if(rand()%10000 < (sd->addeff[i-SC_STONE]+sd->arrow_addeff[i-SC_STONE])*sc_def_card/100 ){
					if(battle_config.battle_log)
						printf("PC %d skill_addeff: card�ɂ��ُ픭�� %d %d\n",sd->bl.id,i,sd->addeff[i-SC_STONE]);
					skill_status_change_start(bl,i,7,0,0,0,(i==SC_CONFUSION)? 10000+7000:skill_get_time2(sc2[i-SC_STONE],7),0);
				}
			}
		}
	}
	return 0;
}

/*=========================================================================
 �X�L���U��������΂�����
-------------------------------------------------------------------------*/
int skill_blown( struct block_list *src, struct block_list *target,int count)
{
	int dx=0,dy=0,nx,ny;
	int x=target->x,y=target->y;
	int ret,prev_state=MS_IDLE;
	int moveblock;
	struct map_session_data *sd=NULL;
	struct mob_data *md=NULL;
	struct pet_data *pd=NULL;

	if(target->type==BL_PC)
		sd=(struct map_session_data *)target;
	else if(target->type==BL_MOB)
		md=(struct mob_data *)target;
	else if(target->type==BL_PET)
		pd=(struct pet_data *)target;
	else return 0;

	if(!(count&0x10000 && (sd||md||pd))){	/* �w��Ȃ��Ȃ�ʒu�֌W������������߂� */
		dx=target->x-src->x; dx=(dx>0)?1:((dx<0)?-1: 0);
		dy=target->y-src->y; dy=(dy>0)?1:((dy<0)?-1: 0);
	}
	if(dx==0 && dy==0){
		int dir=battle_get_dir(target);
		if(dir>=0 && dir<8){
			dx=-dirx[dir];
			dy=-diry[dir];
		}
	}

	ret=path_blownpos(target->m,x,y,dx,dy,count&0xffff);
	nx=ret>>16;
	ny=ret&0xffff;
	moveblock=( x/BLOCK_SIZE != nx/BLOCK_SIZE || y/BLOCK_SIZE != ny/BLOCK_SIZE);

	if(count&0x20000) {
		battle_stopwalking(target,1);
		if(sd){
			sd->to_x=nx;
			sd->to_y=ny;
			sd->walktimer = 1;
			clif_walkok(sd);
			clif_movechar(sd);
		}
		else if(md) {
			md->to_x=nx;
			md->to_y=ny;
			prev_state = md->state.state;
			md->state.state = MS_WALK;
			clif_fixmobpos(md);
		}
		else if(pd) {
			pd->to_x=nx;
			pd->to_y=ny;
			prev_state = pd->state.state;
			pd->state.state = MS_WALK;
			clif_fixpetpos(pd);
		}
	}
	else
		battle_stopwalking(target,2);

	dx = nx - x;
	dy = ny - y;

	if(sd)	/* ��ʊO�ɏo���̂ŏ��� */
		map_foreachinmovearea(clif_pcoutsight,target->m,x-AREA_SIZE,y-AREA_SIZE,x+AREA_SIZE,y+AREA_SIZE,dx,dy,0,sd);
	else if(md)
		map_foreachinmovearea(clif_moboutsight,target->m,x-AREA_SIZE,y-AREA_SIZE,x+AREA_SIZE,y+AREA_SIZE,dx,dy,BL_PC,md);
	else if(pd)
		map_foreachinmovearea(clif_petoutsight,target->m,x-AREA_SIZE,y-AREA_SIZE,x+AREA_SIZE,y+AREA_SIZE,dx,dy,BL_PC,pd);

	if(moveblock) map_delblock(target);
	target->x=nx;
	target->y=ny;
	if(moveblock) map_addblock(target);

	if(sd) {	/* ��ʓ��ɓ����Ă����̂ŕ\�� */
		map_foreachinmovearea(clif_pcinsight,target->m,nx-AREA_SIZE,ny-AREA_SIZE,nx+AREA_SIZE,ny+AREA_SIZE,-dx,-dy,0,sd);
		if(count&0x20000)
			sd->walktimer = -1;
	}
	else if(md) {
		map_foreachinmovearea(clif_mobinsight,target->m,nx-AREA_SIZE,ny-AREA_SIZE,nx+AREA_SIZE,ny+AREA_SIZE,-dx,-dy,BL_PC,md);
		if(count&0x20000)
			md->state.state = prev_state;
	}
	else if(pd) {
		map_foreachinmovearea(clif_petinsight,target->m,nx-AREA_SIZE,ny-AREA_SIZE,nx+AREA_SIZE,ny+AREA_SIZE,-dx,-dy,BL_PC,pd);
		if(count&0x20000)
			pd->state.state = prev_state;
	}

	skill_unit_move(target,gettick(),(count&0xffff)+7);	/* �X�L�����j�b�g�̔��� */

	return 0;
}


/*
 * =========================================================================
 * �X�L���U�����ʏ����܂Ƃ�
 * flag�̐����B16�i�}
 * 	00XRTTff
 *  ff	= magic�Ōv�Z�ɓn�����j
 *	TT	= �p�P�b�g��type����(0�Ńf�t�H���g�j
 *  X   = �p�P�b�g�̃X�L��Lv
 *  R	= �\��iskill_area_sub�Ŏg�p����j
 *-------------------------------------------------------------------------
 */

int skill_attack( int attack_type, struct block_list* src, struct block_list *dsrc,
	 struct block_list *bl,int skillid,int skilllv,unsigned int tick,int flag )
{
	struct Damage dmg;
	struct status_change *sc_data=battle_get_sc_data(bl);
	int type,lv,damage;

	rdamage = 0;
//�������Ȃ����肱������
	if(src == NULL || dsrc == NULL || bl == NULL) //�w�肳��Ă��Ȃ���Ή������Ȃ�
		return 0;
	if(dsrc->m != bl->m) //�Ώۂ������}�b�v�ɂ��Ȃ���Ή������Ȃ�
		return 0;
	if(src->prev == NULL || dsrc->prev == NULL || bl->prev == NULL) //prev�悭�킩��Ȃ���
		return 0;
	if(src->type == BL_PC && pc_isdead((struct map_session_data *)src)) //�p�ҁH��PC�ł��łɎ���ł����牽�����Ȃ�
		return 0;
	if(dsrc->type == BL_PC && pc_isdead((struct map_session_data *)dsrc)) //�p�ҁH��PC�ł��łɎ���ł����牽�����Ȃ�
		return 0;
	if(bl->type == BL_PC && pc_isdead((struct map_session_data *)bl)) //�Ώۂ�PC�ł��łɎ���ł����牽�����Ȃ�
		return 0;
	if(sc_data && sc_data[SC_HIDING].timer != -1) { //�n�C�f�B���O��Ԃ�
		if(skill_get_pl(skillid) != 2) //�X�L���̑������n�����łȂ���Ή������Ȃ�
			return 0;
	}
	if(sc_data && sc_data[SC_TRICKDEAD].timer != -1) //���񂾂ӂ蒆�͉������Ȃ�
		return 0;
	if(skillid == WZ_STORMGUST) { //�g�p�X�L�����X�g�[���K�X�g��
		struct status_change *sc_data = battle_get_sc_data(bl); //�ŏ��ɌĂ�ł�̂ƈႤ�́H��
		if(sc_data && sc_data[SC_FREEZE].timer != -1) //������ԂȂ牽�����Ȃ�
			return 0;
	}
	if(skillid == WZ_FROSTNOVA && dsrc->x == bl->x && dsrc->y == bl->y) //�g�p�X�L�����t���X�g�m���@�ŁAdsrc��bl�������ꏊ�Ȃ牽�����Ȃ�
		return 0;
//�������Ȃ����肱���܂�

	type=-1;
	lv=(flag>>20)&0xf;
	dmg=battle_calc_attack(attack_type,src,bl,skillid,skilllv,flag&0xff ); //�_���[�W�v�Z

//�}�W�b�N���b�h������������
	if(attack_type&BF_MAGIC && sc_data && sc_data[SC_MAGICROD].timer != -1 && src == dsrc) { //���@�U���Ń}�W�b�N���b�h��Ԃ�src=dsrc�Ȃ�
		dmg.damage = dmg.damage2 = 0; //�_���[�W0
		if(bl->type == BL_PC) { //�Ώۂ�PC�̏ꍇ
			int sp = skill_get_sp(skillid,skilllv); //�g�p���ꂽ�X�L����SP���z��
			sp = sp * sc_data[SC_MAGICROD].val2 / 100; //�z�����v�Z
			if(skillid == WZ_WATERBALL && skilllv > 1) //�E�H�[�^�[�{�[��Lv1�ȏ�
				sp = sp/((skilllv|1)*(skilllv|1)); //����Ɍv�Z�H
			if(sp > 0x7fff) sp = 0x7fff; //SP�������̏ꍇ�͗��_�ő�l
			else if(sp < 1) sp = 1; //1�ȉ��̏ꍇ��1
			if(((struct map_session_data *)bl)->status.sp + sp > ((struct map_session_data *)bl)->status.max_sp) { //��SP+���݂�SP��MSP���傫���ꍇ
				sp = ((struct map_session_data *)bl)->status.max_sp - ((struct map_session_data *)bl)->status.sp; //SP��MSP-����SP�ɂ���
				((struct map_session_data *)bl)->status.sp = ((struct map_session_data *)bl)->status.max_sp; //���݂�SP��MSP����
			}
			else //��SP+���݂�SP��MSP��菬�����ꍇ�͉�SP�����Z
				((struct map_session_data *)bl)->status.sp += sp;
			clif_heal(((struct map_session_data *)bl)->fd,SP_SP,sp); //SP�񕜃G�t�F�N�g�̕\��
			((struct map_session_data *)bl)->canact_tick = tick + skill_delayfix(bl, skill_get_delay(SA_MAGICROD,sc_data[SC_MAGICROD].val1)); //
		}
		clif_skill_nodamage(bl,bl,SA_MAGICROD,sc_data[SC_MAGICROD].val1,1); //�}�W�b�N���b�h�G�t�F�N�g��\��
	}
//�}�W�b�N���b�h���������܂�

	damage = dmg.damage + dmg.damage2;

	if(lv==15)
		lv=-1;

	if( flag&0xff00 )
		type=(flag&0xff00)>>8;

	if(damage <= 0 || damage < dmg.div_) //������΂�����H��
		dmg.blewcount = 0;

	if(skillid == CR_GRANDCROSS && src == bl) //�O�����h�N���X�Ŏg�p�҂ƑΏۂ������ꍇ�H��
		dsrc = src;

//�g�p�҂�PC�̏ꍇ�̏�����������
	if(src->type == BL_PC) {
		struct map_session_data *sd = (struct map_session_data *)src;
//�A�ŏ�(MO_CHAINCOMBO)��������
		if(skillid == MO_CHAINCOMBO) {
			int delay = 1000 - 4 * battle_get_agi(src) - 2 *  battle_get_dex(src); //��{�f�B���C�̌v�Z
			if(damage < battle_get_hp(bl)) { //�_���[�W���Ώۂ�HP��菬�����ꍇ
				if(pc_checkskill(sd, MO_COMBOFINISH) > 0 && sd->spiritball >= 0) //�җ���(MO_COMBOFINISH)�擾���C���ێ�����+300ms
					delay += 300 * battle_config.combo_delay_rate /100; //�ǉ��f�B���C��conf�ɂ�蒲��

				skill_status_change_start(src,SC_COMBO,MO_CHAINCOMBO,skilllv,0,0,delay,0); //�R���{��Ԃ�
			}
			sd->attackabletime = sd->canmove_tick = tick + delay;
			clif_combo_delay(src,delay); //�R���{�f�B���C�p�P�b�g�̑��M
		}
//�A�ŏ�(MO_CHAINCOMBO)�����܂�
//�җ���(MO_COMBOFINISH)��������
		else if(skillid == MO_COMBOFINISH) {
			int delay = 700 - 4 * battle_get_agi(src) - 2 *  battle_get_dex(src);
			if(damage < battle_get_hp(bl)) {
				if(pc_checkskill(sd, MO_EXTREMITYFIST) > 0 && sd->spiritball >= 4 && sd->sc_data[SC_EXPLOSIONSPIRITS].timer != -1) //���C���e����(MO_EXTREMITYFIST)�擾���C��4�ێ��������g��(MO_EXPLOSIONSPIRITS)��Ԏ���+300ms
					delay += 300 * battle_config.combo_delay_rate /100; //�ǉ��f�B���C��conf�ɂ�蒲��

				skill_status_change_start(src,SC_COMBO,MO_COMBOFINISH,skilllv,0,0,delay,0); //�R���{��Ԃ�
			}
			sd->attackabletime = sd->canmove_tick = tick + delay;
			clif_combo_delay(src,delay); //�R���{�f�B���C�p�P�b�g�̑��M
		}
	}
//�җ���(MO_COMBOFINISH)�����܂�
//����X�L���H��������
	if(attack_type&BF_WEAPON && damage > 0 && src != bl && src == dsrc) { //����X�L�����_���[�W���聕�g�p�҂ƑΏێ҂��Ⴄ��src=dsrc
		if(dmg.flag&BF_SHORT) { //�ߋ����U�����H��
			if(bl->type == BL_PC) { //�Ώۂ�PC�̎�
				struct map_session_data *tsd = (struct map_session_data *)bl;
				if(tsd->short_weapon_damage_return > 0) { //�ߋ����U�����˕Ԃ��H��
					rdamage += damage * tsd->short_weapon_damage_return / 100;
					if(rdamage < 1) rdamage = 1;
				}
			}
			if(sc_data && sc_data[SC_REFLECTSHIELD].timer != -1) { //���t���N�g�V�[���h��
				rdamage += damage * sc_data[SC_REFLECTSHIELD].val2 / 100; //���˕Ԃ��v�Z
				if(rdamage < 1) rdamage = 1;
			}
		}
		else if(dmg.flag&BF_LONG) { //�������U�����H��
			if(bl->type == BL_PC) { //�Ώۂ�PC�̎�
				struct map_session_data *tsd = (struct map_session_data *)bl;
				if(tsd->long_weapon_damage_return > 0) { //�������U�����˕Ԃ��H��
					rdamage += damage * tsd->long_weapon_damage_return / 100;
					if(rdamage < 1) rdamage = 1;
				}
			}
		}
		if(rdamage > 0)
			clif_damage(src,src,tick, dmg.amotion,0,rdamage,1,4,0);
	}

	if(skillid == WZ_SIGHTRASHER)
		clif_skill_damage(src,bl,tick,dmg.amotion,dmg.dmotion,
			damage, dmg.div_, skillid, (lv!=0)?lv:skilllv, 5);
	else
		clif_skill_damage(dsrc,bl,tick,dmg.amotion,dmg.dmotion,
			damage, dmg.div_, skillid, (lv!=0)?lv:skilllv, (skillid==0)? 5:type );
	if(dmg.blewcount > 0 && !map[src->m].flag.gvg) {	/* ������΂������Ƃ��̃p�P�b�g */
		if(skillid == WZ_SIGHTRASHER)
			skill_blown(src,bl,dmg.blewcount);
		else
			skill_blown(dsrc,bl,dmg.blewcount);
		if(bl->type == BL_MOB)
			clif_fixmobpos((struct mob_data *)bl);
		else if(bl->type == BL_PET)
			clif_fixpetpos((struct pet_data *)bl);
		else
			clif_fixpos(bl);
	}

	map_freeblock_lock();
	/* ���ۂɃ_���[�W�������s�� */
	if(skillid != KN_BOWLINGBASH || flag)
		battle_damage(src,bl,damage,0);
	if(skillid == RG_INTIMIDATE && damage > 0 && !(battle_get_mode(bl)&0x20) && !map[src->m].flag.gvg ) {
		int s_lv = battle_get_lv(src),t_lv = battle_get_lv(bl);
		int rate = 50 + skilllv * 5;
		rate = rate + (s_lv - t_lv);
		if(rand()%100 < rate)
			skill_addtimerskill(src,tick + 800,bl->id,0,0,skillid,skilllv,0,flag);
	}
	if(damage > 0 && dmg.flag&BF_SKILL && bl->type==BL_PC && pc_checkskill((struct map_session_data *)bl,RG_PLAGIARISM)){
		struct map_session_data *tsd = (struct map_session_data *)bl;
		if(!tsd->status.skill[skillid].id && !tsd->status.skill[skillid].id
			&& !(skillid > NPC_PIERCINGATT && skillid < NPC_SUMMONMONSTER) ){
			//���ɓ���ł���X�L��������ΊY���X�L��������
			if (tsd->cloneskill_id && tsd->cloneskill_lv && tsd->status.skill[tsd->cloneskill_id].flag==13){
				tsd->status.skill[tsd->cloneskill_id].id=0;
				tsd->status.skill[tsd->cloneskill_id].lv=0;
				tsd->status.skill[tsd->cloneskill_id].flag=0;
			}
			tsd->cloneskill_id=skillid;
			tsd->cloneskill_lv=skilllv;
			tsd->status.skill[skillid].id=skillid;
			tsd->status.skill[skillid].lv=(pc_checkskill(tsd,RG_PLAGIARISM) > skill_get_max(skillid))?
							skill_get_max(skillid):pc_checkskill(tsd,RG_PLAGIARISM);
			tsd->status.skill[skillid].flag=13;//cloneskill flag
			clif_skillinfoblock(tsd);
		}
	}
	/* �_���[�W������Ȃ�ǉ����ʔ��� */
	if(bl->prev != NULL &&
		(bl->type != BL_PC || (bl->type == BL_PC && !pc_isdead((struct map_session_data *)bl) ) ) ) {
		if(damage > 0)
			skill_additional_effect(src,bl,skillid,skilllv,attack_type,tick);
		if(bl->type==BL_MOB && src!=bl)	/* �X�L���g�p������MOB�X�L�� */
		{
				if(battle_config.mob_changetarget_byskill == 1)
				{
					int target=((struct mob_data *)bl)->target_id;
					if(src->type == BL_PC)
						((struct mob_data *)bl)->target_id=src->id;
					mobskill_use((struct mob_data *)bl,tick,MSC_SKILLUSED|(skillid<<16));
					((struct mob_data *)bl)->target_id=target;
				}
				else
					mobskill_use((struct mob_data *)bl,tick,MSC_SKILLUSED|(skillid<<16));
		}
	}

	if(src->type == BL_PC && dmg.flag&BF_WEAPON && src != bl && src == dsrc && damage > 0) {
		struct map_session_data *sd = (struct map_session_data *)src;
		int hp = 0,sp = 0;
		if(sd->hp_drain_rate && sd->hp_drain_per > 0 && dmg.damage > 0 && rand()%100 < sd->hp_drain_rate) {
			hp += (dmg.damage * sd->hp_drain_per)/100;
			if(sd->hp_drain_rate > 0 && hp < 1) hp = 1;
			else if(sd->hp_drain_rate < 0 && hp > -1) hp = -1;
		}
		if(sd->hp_drain_rate_ && sd->hp_drain_per_ > 0 && dmg.damage2 > 0 && rand()%100 < sd->hp_drain_rate_) {
			hp += (dmg.damage2 * sd->hp_drain_per_)/100;
			if(sd->hp_drain_rate_ > 0 && hp < 1) hp = 1;
			else if(sd->hp_drain_rate_ < 0 && hp > -1) hp = -1;
		}
		if(sd->sp_drain_rate > 0 && sd->sp_drain_per > 0 && dmg.damage > 0 && rand()%100 < sd->sp_drain_rate) {
			sp += (dmg.damage * sd->sp_drain_per)/100;
			if(sd->sp_drain_rate > 0 && sp < 1) sp = 1;
			else if(sd->sp_drain_rate < 0 && sp > -1) sp = -1;
		}
		if(sd->sp_drain_rate_ > 0 && sd->sp_drain_per_ > 0 && dmg.damage2 > 0 && rand()%100 < sd->sp_drain_rate_) {
			sp += (dmg.damage2 * sd->sp_drain_per_)/100;
			if(sd->sp_drain_rate_ > 0 && sp < 1) sp = 1;
			else if(sd->sp_drain_rate_ < 0 && sp > -1) sp = -1;
		}
		if(hp || sp) pc_heal(sd,hp,sp);
	}

	if((skillid != KN_BOWLINGBASH || flag) && rdamage > 0)
		battle_damage(bl,src,rdamage,0);

	if(attack_type&BF_WEAPON && sc_data && sc_data[SC_AUTOCOUNTER].timer != -1 && sc_data[SC_AUTOCOUNTER].val4 > 0) {
		if(sc_data[SC_AUTOCOUNTER].val3 == dsrc->id)
			battle_weapon_attack(bl,dsrc,tick,0x8000|sc_data[SC_AUTOCOUNTER].val1);
		skill_status_change_end(bl,SC_AUTOCOUNTER,-1);
	}

	map_freeblock_unlock();

	return (dmg.damage+dmg.damage2);	/* �^�_����Ԃ� */
}

/*==========================================
 * �X�L���͈͍U���p(map_foreachinarea����Ă΂��)
 * flag�ɂ��āF16�i�}���m�F
 * MSB <- 00fTffff ->LSB
 *	T	=�^�[�Q�b�g�I��p(BCT_*)
 *  ffff=���R�Ɏg�p�\
 *  0	=�\��B0�ɌŒ�
 *------------------------------------------
 */
static int skill_area_temp[8];	/* �ꎞ�ϐ��B�K�v�Ȃ�g���B */
typedef int (*SkillFunc)(struct block_list *,struct block_list *,int,int,unsigned int,int);
int skill_area_sub( struct block_list *bl,va_list ap )
{
	struct block_list *src;
	int skill_id,skill_lv,flag;
	unsigned int tick;
	SkillFunc func;

	if(bl->type!=BL_PC && bl->type!=BL_MOB && bl->type!=BL_SKILL)
		return 0;

	src=va_arg(ap,struct block_list *);
	skill_id=va_arg(ap,int);
	skill_lv=va_arg(ap,int);
	tick=va_arg(ap,unsigned int);
	flag=va_arg(ap,int);
	func=va_arg(ap,SkillFunc);

	if(battle_check_target(src,bl,flag) > 0)
		func(src,bl,skill_id,skill_lv,tick,flag);
	return 0;
}

static int skill_check_unit_range_sub( struct block_list *bl,va_list ap )
{
	struct skill_unit *unit;
	int *c,x,y,range,sx[4],sy[4];
	int t_range,tx[4],ty[4];
	int i,r_flag,skillid;

	if(bl->prev == NULL || bl->type != BL_SKILL)
		return 0;

	unit = (struct skill_unit *)bl;

	if(!unit->alive) return 0;

	c = va_arg(ap,int *);
	x = va_arg(ap,int);
	y = va_arg(ap,int);
	range = va_arg(ap,int);
	skillid = va_arg(ap,int);

	if(skillid == MG_SAFETYWALL || skillid == AL_PNEUMA) {
		if(unit->group->unit_id != 0x7e && unit->group->unit_id != 0x85)
			return 0;
	}
	else if(skillid == AL_WARP) {
		if((unit->group->unit_id < 0x8f || unit->group->unit_id > 0x99) && unit->group->unit_id != 0x92)
			return 0;
	}
	else if((skillid >= HT_SKIDTRAP && skillid <= HT_CLAYMORETRAP) || skillid == HT_TALKIEBOX) {
		if((unit->group->unit_id < 0x8f || unit->group->unit_id > 0x99) && unit->group->unit_id != 0x92)
			return 0;
	}
	else if(skillid == WZ_FIREPILLAR) {
		if(unit->group->unit_id != 0x87)
			return 0;
	}
	else return 0;
	t_range=(unit->range!=0)? unit->range:unit->group->range;
	tx[0] = tx[3] = unit->bl.x - t_range;
	tx[1] = tx[2] = unit->bl.x + t_range;
	ty[0] = ty[1] = unit->bl.y - t_range;
	ty[2] = ty[3] = unit->bl.y + t_range;
	sx[0] = sx[3] = x - range;
	sx[1] = sx[2] = x + range;
	sy[0] = sy[1] = y - range;
	sy[2] = sy[3] = y + range;
	for(i=r_flag=0;i<4;i++) {
		if(sx[i] >= tx[0] && sx[i] <= tx[1] &&  sy[i] >= ty[0] && sy[i] <= ty[2]) {
			r_flag = 1;
			break;
		}
		if(tx[i] >= sx[0] && tx[i] <= sx[1] &&  ty[i] >= sy[0] && ty[i] <= sy[2]) {
			r_flag = 1;
			break;
		}
	}
	if(r_flag) (*c)++;

	return 0;
}

int skill_check_unit_range(int m,int x,int y,int range,int skillid)
{
	int c = 0;

	map_foreachinarea(skill_check_unit_range_sub,m,x-10,y-10,x+10,y+10,BL_SKILL,&c,x,y,range,skillid);

	return c;
}

static int skill_check_unit_range2_sub( struct block_list *bl,va_list ap )
{
	int *c;

	c = va_arg(ap,int *);
	if(bl->prev == NULL || (bl->type != BL_PC && bl->type != BL_MOB))
		return 0;

	if(bl->type == BL_PC && pc_isdead((struct map_session_data *)bl))
		return 0;

	(*c)++;

	return 0;
}

int skill_check_unit_range2(int m,int x,int y,int range)
{
	int c = 0;

	map_foreachinarea(skill_check_unit_range2_sub,m,x-range,y-range,x+range,y+range,0,&c);

	return c;
}

/*=========================================================================
 * �͈̓X�L���g�p������������������
 */
/* �Ώۂ̐����J�E���g����B�iskill_area_temp[0]�����������Ă������Ɓj */
int skill_area_sub_count(struct block_list *src,struct block_list *target,int skillid,int skilllv,unsigned int tick,int flag)
{
	if(skill_area_temp[0] < 0xffff)
		skill_area_temp[0]++;
	return 0;
}

/*==========================================
 *
 *------------------------------------------
 */
static int skill_timerskill(int tid, unsigned int tick, int id,int data )
{
	struct map_session_data *sd = NULL;
	struct mob_data *md = NULL;
	struct block_list *src,*target;
	struct skill_timerskill *skl = NULL;
	int range;

	src = map_id2bl(id);
	if(src == NULL || src->prev == NULL)
		return 0;

	if(src->type == BL_PC) {
		sd = (struct map_session_data *)src;
		skl = &sd->skilltimerskill[data];
	}
	else if(src->type == BL_MOB) {
		md = (struct mob_data *)src;
		skl = &md->skilltimerskill[data];
	}
	else
		return 0;

	skl->timer = -1;
	if(skl->target_id) {
		struct block_list tbl;
		target = map_id2bl(skl->target_id);
		if(skl->skill_id == RG_INTIMIDATE) {
			if(target == NULL) {
				target = &tbl;
				target->type = BL_NUL;
				target->m = src->m;
				target->prev = target->next = NULL;
			}
		}
		if(target == NULL)
			return 0;
		if(target->prev == NULL && skl->skill_id != RG_INTIMIDATE)
			return 0;
		if(src->m != target->m)
			return 0;
		if(sd && pc_isdead(sd))
			return 0;
		if(target->type == BL_PC && pc_isdead((struct map_session_data *)target) && skl->skill_id != RG_INTIMIDATE)
			return 0;

		switch(skl->skill_id) {
			case TF_BACKSLIDING:
				clif_skill_nodamage(src,src,skl->skill_id,skl->skill_lv,1);
				break;
			case RG_INTIMIDATE:
				if(src->type == BL_PC && !map[src->m].flag.noteleport) {
					int x,y,i,j,c;
					pc_randomwarp(sd,3);
					for(i=0;i<16;i++) {
						j = rand()%8;
						x = sd->bl.x + dirx[j];
						y = sd->bl.y + diry[j];
						if((c=map_getcell(sd->bl.m,x,y)) != 1 && c != 5)
							break;
					}
					if(i >= 16) {
						x = sd->bl.x;
						y = sd->bl.y;
					}
					if(target->prev != NULL) {
						if(target->type == BL_PC && !pc_isdead((struct map_session_data *)target))
							pc_setpos((struct map_session_data *)target,map[sd->bl.m].name,x,y,3);
						else if(target->type == BL_MOB)
							mob_warp((struct mob_data *)target,-1,x,y,3);
					}
				}
				else if(src->type == BL_MOB && !map[src->m].flag.monster_noteleport) {
					int x,y,i,j,c;
					mob_warp(md,-1,-1,-1,3);
					for(i=0;i<16;i++) {
						j = rand()%8;
						x = md->bl.x + dirx[j];
						y = md->bl.y + diry[j];
						if((c=map_getcell(md->bl.m,x,y)) != 1 && c != 5)
							break;
					}
					if(i >= 16) {
						x = md->bl.x;
						y = md->bl.y;
					}
					if(target->prev != NULL) {
						if(target->type == BL_PC && !pc_isdead((struct map_session_data *)target))
							pc_setpos((struct map_session_data *)target,map[md->bl.m].name,x,y,3);
						else if(target->type == BL_MOB)
							mob_warp((struct mob_data *)target,-1,x,y,3);
					}
				}
				break;

			case BA_FROSTJOKE:			/* �����W���[�N */
			case DC_SCREAM:				/* �X�N���[�� */
				range=15;		//���E�S��
				map_foreachinarea(skill_frostjoke_scream,src->m,src->x-range,src->y-range,
					src->x+range,src->y+range,0,src,skl->skill_id,skl->skill_lv,tick);
				break;

			default:
				skill_attack(skl->type,src,src,target,skl->skill_id,skl->skill_lv,tick,skl->flag);
				break;
		}
	}
	else {
		if(src->m != skl->map)
			return 0;
		switch(skl->skill_id) {
			case WZ_METEOR:
				if(skl->type >= 0) {
					skill_unitsetting(src,skl->skill_id,skl->skill_lv,skl->type>>16,skl->type&0xFFFF,0);
					clif_skill_poseffect(src,skl->skill_id,skl->skill_lv,skl->x,skl->y,tick);
				}
				else
					skill_unitsetting(src,skl->skill_id,skl->skill_lv,skl->x,skl->y,0);
				break;
		}
	}

	return 0;
}

/*==========================================
 *
 *------------------------------------------
 */
int skill_addtimerskill(struct block_list *src,unsigned int tick,int target,int x,int y,int skill_id,int skill_lv,int type,int flag)
{
	int i;

	if(src->type == BL_PC) {
		struct map_session_data *sd = (struct map_session_data *)src;
		for(i=0;i<MAX_SKILLTIMERSKILL;i++) {
			if(sd->skilltimerskill[i].timer == -1) {
				sd->skilltimerskill[i].timer = add_timer(tick, skill_timerskill, src->id, i);
				sd->skilltimerskill[i].src_id = src->id;
				sd->skilltimerskill[i].target_id = target;
				sd->skilltimerskill[i].skill_id = skill_id;
				sd->skilltimerskill[i].skill_lv = skill_lv;
				sd->skilltimerskill[i].map = src->m;
				sd->skilltimerskill[i].x = x;
				sd->skilltimerskill[i].y = y;
				sd->skilltimerskill[i].type = type;
				sd->skilltimerskill[i].flag = flag;

				return 0;
			}
		}
		return 1;
	}
	else if(src->type == BL_MOB) {
		struct mob_data *md = (struct mob_data *)src;
		for(i=0;i<MAX_MOBSKILLTIMERSKILL;i++) {
			if(md->skilltimerskill[i].timer == -1) {
				md->skilltimerskill[i].timer = add_timer(tick, skill_timerskill, src->id, i);
				md->skilltimerskill[i].src_id = src->id;
				md->skilltimerskill[i].target_id = target;
				md->skilltimerskill[i].skill_id = skill_id;
				md->skilltimerskill[i].skill_lv = skill_lv;
				md->skilltimerskill[i].map = src->m;
				md->skilltimerskill[i].x = x;
				md->skilltimerskill[i].y = y;
				md->skilltimerskill[i].type = type;
				md->skilltimerskill[i].flag = flag;

				return 0;
			}
		}
		return 1;
	}

	return 1;
}

/*==========================================
 *
 *------------------------------------------
 */
int skill_cleartimerskill(struct block_list *src)
{
	int i;

	if(src->type == BL_PC) {
		struct map_session_data *sd = (struct map_session_data *)src;
		for(i=0;i<MAX_SKILLTIMERSKILL;i++) {
			if(sd->skilltimerskill[i].timer != -1) {
				delete_timer(sd->skilltimerskill[i].timer, skill_timerskill);
				sd->skilltimerskill[i].timer = -1;
			}
		}
	}
	else if(src->type == BL_MOB) {
		struct mob_data *md = (struct mob_data *)src;
		for(i=0;i<MAX_MOBSKILLTIMERSKILL;i++) {
			if(md->skilltimerskill[i].timer != -1) {
				delete_timer(md->skilltimerskill[i].timer, skill_timerskill);
				md->skilltimerskill[i].timer = -1;
			}
		}
	}

	return 0;
}

/* �͈̓X�L���g�p���������������܂�
 * -------------------------------------------------------------------------
 */


/*==========================================
 * �X�L���g�p�i�r�������AID�w��U���n�j
 * �i�X�p�Q�b�e�B�Ɍ����ĂP���O�i�I(�_���|)�j
 *------------------------------------------
 */
int skill_castend_damage_id( struct block_list* src, struct block_list *bl,int skillid,int skilllv,unsigned int tick,int flag )
{
	struct map_session_data *sd=NULL;
	int i;

	if(src->type==BL_PC)
		sd=(struct map_session_data *)src;
	if(sd && pc_isdead(sd))
		return 1;

	if((skillid == WZ_SIGHTRASHER || skillid == CR_GRANDCROSS) && src != bl)
		bl = src;
	if(bl == NULL || bl->prev == NULL)
		return 1;
	if(bl->type == BL_PC && pc_isdead((struct map_session_data *)bl))
		return 1;
	map_freeblock_lock();
	switch(skillid)
	{
	/* ����U���n�X�L�� */
	case SM_BASH:			/* �o�b�V�� */
	case MC_MAMMONITE:		/* ���}�[�i�C�g */
	case AC_DOUBLE:			/* �_�u���X�g���C�t�B���O */
	case AS_SONICBLOW:		/* �\�j�b�N�u���[ */
	case KN_PIERCE:			/* �s�A�[�X */
	case KN_SPEARBOOMERANG:	/* �X�s�A�u�[������ */
	case TF_POISON:			/* �C���x�i�� */
	case TF_SPRINKLESAND:	/* ���܂� */
	case AC_CHARGEARROW:	/* �`���[�W�A���[ */
	case KN_SPEARSTAB:		/* �X�s�A�X�^�u */
	case RG_RAID:		/* �T�v���C�Y�A�^�b�N */
	case RG_INTIMIDATE:		/* �C���e�B�~�f�C�g */
	case BA_MUSICALSTRIKE:	/* �~���[�W�J���X�g���C�N */
	case DC_THROWARROW:		/* ��� */
	case BA_DISSONANCE:		/* �s���a�� */
	case CR_HOLYCROSS:		/* �z�[���[�N���X */
	case CR_SHIELDCHARGE:
	case CR_SHIELDBOOMERANG:
	/* �ȉ�MOB��p */
	/* �P�̍U���ASP�����U���A�������U���A�h�䖳���U���A���i�U�� */
	case NPC_PIERCINGATT:
	case NPC_MENTALBREAKER:
	case NPC_RANGEATTACK:
	case NPC_CRITICALSLASH:
	case NPC_COMBOATTACK:
	/* �K���U���A�ōU���A�Í��U���A���ٍU���A�X�^���U�� */
	case NPC_GUIDEDATTACK:
	case NPC_POISON:
	case NPC_BLINDATTACK:
	case NPC_SILENCEATTACK:
	case NPC_STUNATTACK:
	/* �Ή��U���A�􂢍U���A�����U���A�����_��ATK�U�� */
	case NPC_PETRIFYATTACK:
	case NPC_CURSEATTACK:
	case NPC_SLEEPATTACK:
	case NPC_RANDOMATTACK:
	/* �������U���A�n�����U���A�Α����U���A�������U�� */
	case NPC_WATERATTACK:
	case NPC_GROUNDATTACK:
	case NPC_FIREATTACK:
	case NPC_WINDATTACK:
	/* �ő����U���A�������U���A�ő����U���A�O�����U���ASP�����U�� */
	case NPC_POISONATTACK:
	case NPC_HOLYATTACK:
	case NPC_DARKNESSATTACK:
	case NPC_TELEKINESISATTACK:
		skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,flag);
		break;
	case NPC_DARKBREATH:
		clif_emotion(src,7);
		skill_attack(BF_MISC,src,src,bl,skillid,skilllv,tick,flag);
		break;
	case MO_INVESTIGATE:	/* ���� */
		{
			struct status_change *sc_data = battle_get_sc_data(src);
			skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,flag);
			if(sc_data[SC_BLADESTOP].timer != -1)
				skill_status_change_end(src,SC_BLADESTOP,-1);
		}
		break;
	case KN_BRANDISHSPEAR:		/* �u�����f�B�b�V���X�s�A */
		{
			struct mob_data* mb=(struct mob_data*)bl;

			skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,flag);
			if(mb->hp > 0){
				skill_blown(src,bl,skill_get_blewcount(skillid,skilllv));
				if(bl->type == BL_MOB)
					clif_fixmobpos((struct mob_data *)bl);
				else if(bl->type == BL_PET)
					clif_fixpetpos((struct pet_data *)bl);
				else
					clif_fixpos(bl);
			}
		}
		break;
	case RG_BACKSTAP:		/* �o�b�N�X�^�u */
		{
			int dir = map_calc_dir(src,bl->x,bl->y),t_dir = battle_get_dir(bl);
			int dist = distance(src->x,src->y,bl->x,bl->y);
			if((dist > 0 && !map_check_dir(dir,t_dir)) || bl->type == BL_SKILL) {
				struct status_change *sc_data = battle_get_sc_data(src);
				if(sc_data && sc_data[SC_HIDING].timer != -1)
					skill_status_change_end(src, SC_HIDING, -1);	// �n�C�f�B���O����
				skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,flag);
			}
			else if(src->type == BL_PC)
				clif_skill_fail(sd,sd->skillid,0,0);
		}
		break;

	case AM_ACIDTERROR:		/* �A�V�b�h�e���[ */
		skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,flag);
//		if(bl->type == BL_PC && rand()%100 < skill_get_time(skillid,skilllv))
//			pc_break_armor((struct map_session_data *)bl);
		break;
	case MO_FINGEROFFENSIVE:	/* �w�e */
		{
			struct status_change *sc_data = battle_get_sc_data(src);

			if(!battle_config.finger_offensive_type)
				skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,flag);
			else {
				skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,flag);
				if(sd) {
					for(i=1;i<sd->spiritball_old;i++)
						skill_addtimerskill(src,tick+i*200,bl->id,0,0,skillid,skilllv,BF_WEAPON,flag);
					sd->canmove_tick = tick + (sd->spiritball_old-1)*200;
				}
			}
			if(sc_data[SC_BLADESTOP].timer != -1)
				skill_status_change_end(src,SC_BLADESTOP,-1);
		}
		break;
	case MO_CHAINCOMBO:		/* �A�ŏ� */
		{
			struct status_change *sc_data = battle_get_sc_data(src);
			skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,flag);
			if(sc_data[SC_BLADESTOP].timer != -1)
				skill_status_change_end(src,SC_BLADESTOP,-1);
		}
		break;
	case MO_COMBOFINISH:	/* �җ��� */
		skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,flag);
		break;
	case MO_EXTREMITYFIST:	/* ���C���e�P�� */
		{
			struct status_change *sc_data = battle_get_sc_data(src);

			if(sd) {
				struct walkpath_data wpd;
				int dx,dy;

				dx = bl->x - sd->bl.x;
				dy = bl->y - sd->bl.y;
				if(dx > 0) dx++;
				else if(dx < 0) dx--;
				if(dy > 0) dy++;
				else if(dy < 0) dy--;
				if(dx == 0 && dy == 0) dx++;
				if(path_search(&wpd,src->m,sd->bl.x,sd->bl.y,sd->bl.x+dx,sd->bl.y+dy,1) == -1) {
					dx = bl->x - sd->bl.x;
					dy = bl->y - sd->bl.y;
					if(path_search(&wpd,src->m,sd->bl.x,sd->bl.y,sd->bl.x+dx,sd->bl.y+dy,1) == -1) {
						clif_skill_fail(sd,sd->skillid,0,0);
						break;
					}
				}
				sd->to_x = sd->bl.x + dx;
				sd->to_y = sd->bl.y + dy;
				skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,flag);
				clif_walkok(sd);
				clif_movechar(sd);
				if(dx < 0) dx = -dx;
				if(dy < 0) dy = -dy;
				sd->attackabletime = sd->canmove_tick = tick + 100 + sd->speed * ((dx > dy)? dx:dy);
				if(sd->canact_tick < sd->canmove_tick)
					sd->canact_tick = sd->canmove_tick;
				pc_movepos(sd,sd->to_x,sd->to_y);
				skill_status_change_end(&sd->bl,SC_COMBO,-1);
			}
			else
				skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,flag);
			skill_status_change_end(src, SC_EXPLOSIONSPIRITS, -1);
			if(sc_data[SC_BLADESTOP].timer != -1)
				skill_status_change_end(src,SC_BLADESTOP,-1);
		}
		break;
	/* ����n�͈͍U���X�L�� */
	case AC_SHOWER:			/* �A���[�V�����[ */
	case SM_MAGNUM:			/* �}�O�i���u���C�N */
	case AS_GRIMTOOTH:		/* �O�����g�D�[�X */
	case MC_CARTREVOLUTION:	/* �J�[�g�����H�����[�V���� */
	case NPC_SPLASHATTACK:	/* �X�v���b�V���A�^�b�N */
		if(flag&1){
			/* �ʂɃ_���[�W��^���� */
			if(bl->id!=skill_area_temp[1]){
				int dist=0;
				if(skillid==SM_MAGNUM){	/* �}�O�i���u���C�N�Ȃ璆�S����̋������v�Z */
					int dx=abs( bl->x - skill_area_temp[2] );
					int dy=abs( bl->y - skill_area_temp[3] );
					dist=((dx>dy)?dx:dy);
				}
				skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,
					0x0500|dist  );
			}
		}else{
			int ar=1;
			int x=bl->x,y=bl->y;
			if( skillid==SM_MAGNUM){
				x=src->x;
				y=src->y;
			}else if(skillid==AC_SHOWER)	/* �A���[�V�����[�͈� */
				ar=2;
			else if(skillid==NPC_SPLASHATTACK)	/* �X�v���b�V���A�^�b�N�͔͈�7*7 */
				ar=3;
			skill_area_temp[1]=bl->id;
			skill_area_temp[2]=x;
			skill_area_temp[3]=y;
			/* �܂��^�[�Q�b�g�ɍU���������� */
			skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,0);
			/* ���̌�^�[�Q�b�g�ȊO�͈͓̔��̓G�S�̂ɏ������s�� */
			map_foreachinarea(skill_area_sub,
				bl->m,x-ar,y-ar,x+ar,y+ar,0,
				src,skillid,skilllv,tick, flag|BCT_ENEMY|1,
				skill_castend_damage_id);
		}
		break;

	case KN_BOWLINGBASH:	/* �{�E�����O�o�b�V�� */
		if(flag&1){
			/* �ʂɃ_���[�W��^���� */
			if(bl->id!=skill_area_temp[1])
				skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,0x0500);
		}
		else {
			int damage;
			map_freeblock_lock();
			damage = skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,0);
			if(damage > 0) {
				int i,c;	/* ���l���畷���������Ȃ̂ŊԈ���Ă�\���偕������������������ */
				c = skill_get_blewcount(skillid,skilllv);
				if(map[bl->m].flag.gvg) c = 0;
				for(i=0;i<c;i++){
					skill_blown(src,bl,1);
					if(bl->type == BL_MOB)
						clif_fixmobpos((struct mob_data *)bl);
					else if(bl->type == BL_PET)
						clif_fixpetpos((struct pet_data *)bl);
					else
						clif_fixpos(bl);
					skill_area_temp[0]=0;
					map_foreachinarea(skill_area_sub,
						bl->m,bl->x-1,bl->y-1,bl->x+1,bl->y+1,0,
						src,skillid,skilllv,tick, flag|BCT_ENEMY ,
						skill_area_sub_count);
					if(skill_area_temp[0]>1) break;
				}
				skill_area_temp[1]=bl->id;
				skill_area_temp[2]=bl->x;
				skill_area_temp[3]=bl->y;
				/* ���̌�^�[�Q�b�g�ȊO�͈͓̔��̓G�S�̂ɏ������s�� */
				map_foreachinarea(skill_area_sub,
					bl->m,bl->x-1,bl->y-1,bl->x+1,bl->y+1,0,
					src,skillid,skilllv,tick, flag|BCT_ENEMY|1,
					skill_castend_damage_id);
				battle_damage(src,bl,damage,1);
				if(rdamage > 0)
					battle_damage(bl,src,rdamage,0);
			}
			map_freeblock_unlock();
		}
		break;

	case ALL_RESURRECTION:		/* ���U���N�V���� */
	case PR_TURNUNDEAD:			/* �^�[���A���f�b�h */
		if(bl->type != BL_PC && battle_check_undead(battle_get_race(bl),battle_get_elem_type(bl)))
			skill_attack(BF_MAGIC,src,src,bl,skillid,skilllv,tick,flag);
		else {
			map_freeblock_unlock();
			return 1;
		}
		break;

	/* ���@�n�X�L�� */
	case MG_SOULSTRIKE:			/* �\�E���X�g���C�N */
	case MG_COLDBOLT:			/* �R�[���h�{���g */
	case MG_FIREBOLT:			/* �t�@�C�A�[�{���g */
	case MG_LIGHTNINGBOLT:		/* ���C�g�j���O�{���g */
	case WZ_EARTHSPIKE:			/* �A�[�X�X�p�C�N */
	case AL_HEAL:				/* �q�[�� */
	case AL_HOLYLIGHT:			/* �z�[���[���C�g */
	case MG_FROSTDIVER:			/* �t���X�g�_�C�o�[ */
	case WZ_JUPITEL:			/* ���s�e���T���_�[ */
	case NPC_MAGICALATTACK:		/* MOB:���@�Ō��U�� */
		skill_attack(BF_MAGIC,src,src,bl,skillid,skilllv,tick,flag);
		break;

	case WZ_WATERBALL:			/* �E�H�[�^�[�{�[�� */
		skill_attack(BF_MAGIC,src,src,bl,skillid,skilllv,tick,flag);
		if(skilllv>1)
			skill_status_change_start(src,SC_WATERBALL,skilllv,bl->id,0,0,0,0);
		break;

	case PR_BENEDICTIO:			/* ���̍~�� */
		if(battle_get_race(bl)==1 || battle_get_race(bl)==6)
			skill_attack(BF_MAGIC,src,src,bl,skillid,skilllv,tick,flag);
		break;

	/* ���@�n�͈͍U���X�L�� */
	case MG_NAPALMBEAT:			/* �i�p�[���r�[�g */
	case MG_FIREBALL:			/* �t�@�C���[�{�[�� */
		if(flag&1){
			/* �ʂɃ_���[�W��^���� */
			if(bl->id!=skill_area_temp[1]){
				if(skillid==MG_FIREBALL){	/* �t�@�C���[�{�[���Ȃ璆�S����̋������v�Z */
					int dx=abs( bl->x - skill_area_temp[2] );
					int dy=abs( bl->y - skill_area_temp[3] );
					skill_area_temp[0]=((dx>dy)?dx:dy);
				}
				skill_attack(BF_MAGIC,src,src,bl,skillid,skilllv,tick,
					skill_area_temp[0]| 0x0500);
			}
		}else{
			int ar=(skillid==MG_NAPALMBEAT)?1:2;
			skill_area_temp[1]=bl->id;
			if(skillid==MG_NAPALMBEAT){	/* �i�p�[���ł͐�ɐ����� */
				skill_area_temp[0]=0;
				map_foreachinarea(skill_area_sub,
					bl->m,bl->x-1,bl->y-1,bl->x+1,bl->y+1,0,
					src,skillid,skilllv,tick, flag|BCT_ENEMY ,
					skill_area_sub_count);
			}else{
				skill_area_temp[0]=0;
				skill_area_temp[2]=bl->x;
				skill_area_temp[3]=bl->y;
			}
			/* �܂��^�[�Q�b�g�ɍU���������� */
			skill_attack(BF_MAGIC,src,src,bl,skillid,skilllv,tick,
					skill_area_temp[0] );
			/* ���̌�^�[�Q�b�g�ȊO�͈͓̔��̓G�S�̂ɏ������s�� */
			map_foreachinarea(skill_area_sub,
				bl->m,bl->x-ar,bl->y-ar,bl->x+ar,bl->y+ar,0,
				src,skillid,skilllv,tick, flag|BCT_ENEMY|1,
				skill_castend_damage_id);
		}
		break;

	case WZ_FROSTNOVA:			/* �t���X�g�m���@ */
		skill_castend_pos2(src,bl->x,bl->y,skillid,skilllv,tick,0);
		break;

	case WZ_SIGHTRASHER:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		skill_castend_pos2(src,bl->x,bl->y,skillid,skilllv,tick,0);
		skill_status_change_end(src,SC_SIGHT,-1);
		break;

	/* ���̑� */
	case HT_BLITZBEAT:			/* �u���b�c�r�[�g */
		if(flag&1){
			/* �ʂɃ_���[�W��^���� */
			if(bl->id!=skill_area_temp[1])
				skill_attack(BF_MISC,src,src,bl,skillid,skilllv,tick,skill_area_temp[0]|(flag&0xf00000));
		}else{
			skill_area_temp[0]=0;
			skill_area_temp[1]=bl->id;
			if(flag&0xf00000)
				map_foreachinarea(skill_area_sub,bl->m,bl->x-1,bl->y-1,bl->x+1,bl->y+1,0,
					src,skillid,skilllv,tick, flag|BCT_ENEMY ,skill_area_sub_count);
			/* �܂��^�[�Q�b�g�ɍU���������� */
			skill_attack(BF_MISC,src,src,bl,skillid,skilllv,tick,skill_area_temp[0]|(flag&0xf00000));
			/* ���̌�^�[�Q�b�g�ȊO�͈͓̔��̓G�S�̂ɏ������s�� */
			map_foreachinarea(skill_area_sub,
				bl->m,bl->x-1,bl->y-1,bl->x+1,bl->y+1,0,
				src,skillid,skilllv,tick, flag|BCT_ENEMY|1,
				skill_castend_damage_id);
		}
		break;

	case CR_GRANDCROSS:			/* �O�����h�N���X */
		/* �X�L�����j�b�g�z�u */
		skill_castend_pos2(src,bl->x,bl->y,skillid,skilllv,tick,0);
		if(sd)
			sd->canmove_tick = tick + 900;
		else if(src->type == BL_MOB)
			mob_changestate((struct mob_data *)src,MS_DELAY,900);
		break;

	case TF_THROWSTONE:			/* �Γ��� */
	case NPC_SMOKING:			/* �X���[�L���O */
		skill_attack(BF_MISC,src,src,bl,skillid,skilllv,tick,0 );
		break;

	case NPC_SELFDESTRUCTION:	/* ���� */
		if(flag&1){
			/* �ʂɃ_���[�W��^���� */
			if(src->type==BL_MOB){
				struct mob_data* mb=(struct mob_data*)src;
				mb->hp=skill_area_temp[2];
				if(bl->id!=skill_area_temp[1])
					skill_attack(BF_MISC,src,src,bl,skillid,skilllv,tick,flag );
				mb->hp=1;
			}
		}else{
			skill_area_temp[1]=bl->id;
			skill_area_temp[2]=battle_get_hp(src);
			/* �܂��^�[�Q�b�g�ɍU���������� */
			skill_attack(BF_MISC,src,src,bl,skillid,skilllv,tick,flag );
			/* ���̌�^�[�Q�b�g�ȊO�͈͓̔��̓G�S�̂ɏ������s�� */
			map_foreachinarea(skill_area_sub,
				bl->m,bl->x-5,bl->y-5,bl->x+5,bl->y+5,0,
				src,skillid,skilllv,tick, flag|BCT_ALL|1,
				skill_castend_damage_id);
			battle_damage(src,src,1,0);
		}
		break;

	/* HP�z��/HP�z�����@ */
	case NPC_BLOODDRAIN:
	case NPC_ENERGYDRAIN:
		{
			int heal;
			heal = skill_attack((skillid==NPC_BLOODDRAIN)?BF_WEAPON:BF_MAGIC,src,src,bl,skillid,skilllv,tick,flag);
			if( heal > 0 ){
				struct block_list tbl;
				tbl.id = 0;
				tbl.m = src->m;
				tbl.x = src->x;
				tbl.y = src->y;
				clif_skill_nodamage(&tbl,src,AL_HEAL,heal,1);
				battle_heal(NULL,src,heal,0,0);
			}
		}
		break;
	case 0:
		if(sd) {
			if(flag&3){
				if(bl->id!=skill_area_temp[1])
					skill_attack(BF_WEAPON,src,src,bl,skillid,skilllv,tick,0x0500);
			}
			else{
				int ar=sd->splash_range;
				skill_area_temp[1]=bl->id;
				map_foreachinarea(skill_area_sub,
					bl->m, bl->x - ar, bl->y - ar, bl->x + ar, bl->y + ar, 0,
					src, skillid, skilllv, tick, flag | BCT_ENEMY | 1,
					skill_castend_damage_id);
			}
		}
		break;

	default:
		map_freeblock_unlock();
		return 1;
	}
	map_freeblock_unlock();

	return 0;
}

/*==========================================
 * �X�L���g�p�i�r�������AID�w��x���n�j
 *------------------------------------------
 */
int skill_castend_nodamage_id( struct block_list *src, struct block_list *bl,int skillid,int skilllv,unsigned int tick,int flag )
{
	struct map_session_data *sd=NULL;
	struct map_session_data *dstsd=NULL;
	struct mob_data *md=NULL;
	struct mob_data *dstmd=NULL;
	int i,abra_skillid=0,abra_skilllv;
	int sc_def_vit,sc_def_mdef,strip_fix,strip_time,strip_per;

	//�N���X�`�F���W�p�{�X�����X�^�[ID
	int changeclass[]={1038,1039,1046,1059,1086,1087,1112,1115
				,1157,1159,1190,1272,1312,1373,1492};
	int poringclass[]={1002};

	if(src->type==BL_PC)
		sd=(struct map_session_data *)src;
	else if(src->type==BL_MOB)
		md=(struct mob_data *)src;

	sc_def_vit = 100 - (3 + battle_get_vit(bl) + battle_get_luk(bl)/3);
	sc_def_mdef = 100 - (3 + battle_get_mdef(bl) + battle_get_luk(bl)/3);
	strip_fix = battle_get_dex(src) - battle_get_dex(bl);

	if(bl->type==BL_PC)
		dstsd=(struct map_session_data *)bl;
	else if(bl->type==BL_MOB){
		dstmd=(struct mob_data *)bl;
		if(sc_def_vit>50)
			sc_def_vit=50;
		if(sc_def_mdef>50)
			sc_def_mdef=50;
	}
	if(sc_def_vit < 0)
		sc_def_vit=0;
	if(sc_def_mdef < 0)
		sc_def_mdef=0;
	if(strip_fix < 0)
		strip_fix=0;

	if(bl == NULL || bl->prev == NULL)
		return 1;
	if(sd && pc_isdead(sd))
		return 1;
	if(dstsd && pc_isdead(dstsd) && skillid != ALL_RESURRECTION)
		return 1;
	if(battle_get_class(bl) == 1288)
		return 1;

	map_freeblock_lock();
	switch(skillid)
	{
	case AL_HEAL:				/* �q�[�� */
		{
			int heal=skill_calc_heal( src, skilllv );
			int heal_get_jobexp;
			if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
				heal=0;	/* ����峃J�[�h�i�q�[���ʂO�j */
			clif_skill_nodamage(src,bl,skillid,heal,1);
			heal_get_jobexp = battle_heal(NULL,bl,heal,0,0);

			// JOB�o���l�l��
			if(src->type == BL_PC && bl->type==BL_PC && heal > 0 && src != bl && battle_config.heal_exp > 0){
				heal_get_jobexp = heal_get_jobexp * battle_config.heal_exp / 100;
				if(heal_get_jobexp <= 0)
					heal_get_jobexp = 1;
				pc_gainexp((struct map_session_data *)src,0,heal_get_jobexp);
			}
		}
		break;

	case ALL_RESURRECTION:		/* ���U���N�V���� */
		if(bl->type==BL_PC){
			int per=0;
			struct map_session_data *tsd=(struct map_session_data*)bl;

			if( (map[bl->m].flag.pvp) && tsd->pvp_point<0 )
				break;			/* PVP�ŕ����s�\��� */

			if(pc_isdead(tsd)){	/* ���S���� */
				clif_skill_nodamage(src,bl,skillid,skilllv,1);
				switch(skilllv){
				case 1: per=10; break;
				case 2: per=30; break;
				case 3: per=50; break;
				case 4: per=80; break;
				}
				tsd->status.hp=tsd->status.max_hp*per/100;
				if(tsd->status.hp<=0) tsd->status.hp=1;
				if(tsd->special_state.restart_full_recover ){	/* �I�V���X�J�[�h */
					tsd->status.hp=tsd->status.max_hp;
					tsd->status.sp=tsd->status.max_sp;
				}
				pc_setstand(tsd);
				if(battle_config.pc_invincible_time > 0)
					pc_setinvincibletimer(tsd,battle_config.pc_invincible_time);
				clif_updatestatus(tsd,SP_HP);
				clif_resurrection(&tsd->bl,1);
				if(src != bl && sd && battle_config.resurrection_exp > 0) {
					int exp = 0,jexp = 0;
					int lv = tsd->status.base_level - sd->status.base_level, jlv = tsd->status.job_level - sd->status.job_level;
					if(lv > 0) {
						exp = (int)((double)tsd->status.base_exp * (double)lv * (double)battle_config.resurrection_exp / 1000000.);
						if(exp < 1) exp = 1;
					}
					if(jlv > 0) {
						jexp = (int)((double)tsd->status.job_exp * (double)lv * (double)battle_config.resurrection_exp / 1000000.);
						if(jexp < 1) jexp = 1;
					}
					if(exp > 0 || jexp > 0)
						pc_gainexp(sd,exp,jexp);
				}
			}
		}
		break;

	case AL_DECAGI:			/* ���x���� */
		if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
			break;
		if( rand()%100 < (50+skilllv*3+(battle_get_lv(src)+battle_get_int(src)/5)-sc_def_mdef) ) {
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0);
		}
		break;

	case AL_CRUCIS:
		if(flag&1) {
			int race = battle_get_race(bl),ele = battle_get_elem_type(bl);
			if(battle_check_target(src,bl,BCT_ENEMY) && (race == 6 || battle_check_undead(race,ele))) {
				int slv=battle_get_lv(src),tlv=battle_get_lv(bl),rate;
				rate = 25 + skilllv*2 + slv - tlv;
				if(rand()%100 < rate)
					skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,0,0);
			}
		}
		else {
			int range = 15;
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			map_foreachinarea(skill_area_sub,
				src->m,src->x-range,src->y-range,src->x+range,src->y+range,0,
				src,skillid,skilllv,tick, flag|BCT_ENEMY|1,
				skill_castend_nodamage_id);
		}
		break;

	case PR_LEXDIVINA:		/* ���b�N�X�f�B�r�[�i */
		{
			struct status_change *sc_data = battle_get_sc_data(bl);
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
				break;
			if(sc_data && sc_data[SC_DIVINA].timer != -1)
				skill_status_change_end(bl,SC_DIVINA,-1);
			else if( rand()%100 < sc_def_vit ) {
				skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0);
			}
		}
		break;
	case SA_ABRACADABRA:
		do{
			abra_skillid=skill_abra_dataset(skilllv);
		}while(abra_skillid == 0);
		abra_skilllv=skill_get_max(abra_skillid)>pc_checkskill(sd,SA_ABRACADABRA)?pc_checkskill(sd,SA_ABRACADABRA):skill_get_max(abra_skillid);
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		sd->skillitem=abra_skillid;
		sd->skillitemlv=abra_skilllv;
		clif_item_skill(sd,abra_skillid,abra_skilllv,"�A�u���J�_�u��");
		break;
	case SA_COMA:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
			break;
		if(dstsd){
			dstsd->status.hp=1;
			dstsd->status.sp=1;
			clif_updatestatus(dstsd,SP_HP);
			clif_updatestatus(dstsd,SP_SP);
		}
		if(dstmd) dstmd->hp=1;
		break;
	case SA_FULLRECOVERY:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
			break;
		if(dstsd) pc_heal(dstsd,dstsd->status.max_hp,dstsd->status.max_sp);
		if(dstmd) dstmd->hp=battle_get_max_hp(&dstmd->bl);
		break;
	case SA_SUMMONMONSTER:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if (sd) mob_once_spawn(sd,map[sd->bl.m].name,sd->bl.x,sd->bl.y,"--ja--",-1,1,"");
		break;
	case SA_LEVELUP:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if (sd && pc_nextbaseexp(sd)) pc_gainexp(sd,pc_nextbaseexp(sd)*10/100,0);
		break;

	case SA_INSTANTDEATH:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if (sd) pc_damage(NULL,sd,sd->status.max_hp);
		break;

	case SA_QUESTION:
	case SA_GRAVITY:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		break;
	case SA_CLASSCHANGE:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if(dstmd) mob_class_change(dstmd,changeclass);
		break;
	case SA_MONOCELL:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if(dstmd) mob_class_change(dstmd,poringclass);
		break;
	case SA_DEATH:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if (dstsd) pc_damage(NULL,dstsd,dstsd->status.max_hp);
		if (dstmd) mob_damage(NULL,dstmd,dstmd->hp,1);
		break;
	case SA_REVERSEORCISH:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if (dstsd) pc_setoption(dstsd,dstsd->status.option|0x0800);
		break;
	case SA_FORTUNE:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if(sd) pc_getzeny(sd,battle_get_lv(bl)*100);
		break;
	case SA_TAMINGMONSTER:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if (dstmd){
			for(i=0;i<MAX_PET_DB;i++){
				if(dstmd->class == pet_db[i].class){
					pet_catch_process1(sd,dstmd->class);
					break;
				}
			}
		}
		break;
	case AL_INCAGI:			/* ���x���� */
	case AL_BLESSING:		/* �u���b�V���O */
	case PR_SLOWPOISON:
	case PR_IMPOSITIO:		/* �C���|�V�e�B�I�}�k�X */
	case PR_ASPERSIO:		/* �A�X�y���V�I */
	case PR_LEXAETERNA:		/* ���b�N�X�G�[�e���i */
	case PR_SUFFRAGIUM:		/* �T�t���M�E�� */
	case PR_BENEDICTIO:		/* ���̍~�� */
	case CR_PROVIDENCE:		/* �v�����B�f���X */
	case SA_FLAMELAUNCHER:	/* �t���C�������`���[ */
	case SA_FROSTWEAPON:	/* �t���X�g�E�F�|�� */
	case SA_LIGHTNINGLOADER:/* ���C�g�j���O���[�_�[ */
	case SA_SEISMICWEAPON:	/* �T�C�Y�~�b�N�E�F�|�� */
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
			break;
		skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0 );
		break;
	case PR_KYRIE:			/* �L���G�G���C�\�� */
		clif_skill_nodamage(bl,bl,skillid,skilllv,1);
		if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
			break;
		skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0 );
		break;
	case KN_AUTOCOUNTER:		/* �I�[�g�J�E���^�[ */
	case KN_TWOHANDQUICKEN:	/* �c�[�n���h�N�C�b�P�� */
	case CR_SPEARQUICKEN:	/* �X�s�A�N�C�b�P�� */
	case CR_REFLECTSHIELD:
	case AS_ENCHANTPOISON:	/* �G���`�����g�|�C�Y�� */
	case AS_POISONREACT:	/* �|�C�Y�����A�N�g */
	case MC_LOUD:			/* ���E�h�{�C�X */
	case MG_ENERGYCOAT:		/* �G�i�W�[�R�[�g */
	case SM_ENDURE:			/* �C���f���A */
	case MG_SIGHT:			/* �T�C�g */
	case AL_RUWACH:			/* ���A�t */
	case MO_EXPLOSIONSPIRITS:	// �����g��
	case MO_STEELBODY:		// ����
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0 );
		break;
	case MC_CHANGECART:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		break;
	case AC_CONCENTRATION:	/* �W���͌��� */
		{
			int range = 1;
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0 );
			map_foreachinarea( skill_status_change_timer_sub,
				src->m, src->x-range, src->y-range, src->x+range,src->y+range,0,
				src,SkillStatusChangeTable[skillid],tick);
		}
		break;
	case SM_PROVOKE:		/* �v���{�b�N */
		{
			struct status_change *sc_data = battle_get_sc_data(bl);

			/* MVPmob�ɂ͌����Ȃ� */
			if(bl->type==BL_MOB && battle_get_mode(bl)&0x20) {
				map_freeblock_unlock();
				return 1;
			}

			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0 );

			if(dstmd && dstmd->skilltimer!=-1 && dstmd->state.skillcastcancel)	// �r���W�Q
				skill_castcancel(bl,0);
			if(dstsd && dstsd->skilltimer!=-1 && (!dstsd->special_state.no_castcancel || map[bl->m].flag.gvg)
				&& dstsd->state.skillcastcancel	&& !dstsd->special_state.no_castcancel2)
				skill_castcancel(bl,0);

			if(sc_data){
				if(sc_data[SC_FREEZE].timer!=-1)
					skill_status_change_end(bl,SC_FREEZE,-1);
				if(sc_data[SC_STONE].timer!=-1 && sc_data[SC_STONE].val2==0)
					skill_status_change_end(bl,SC_STONE,-1);
				if(sc_data[SC_SLEEP].timer!=-1)
					skill_status_change_end(bl,SC_SLEEP,-1);
			}

			if(bl->type==BL_MOB) {
				int range = skill_get_range(skillid,skilllv);
				if(range < 0)
					range = battle_get_range(src) - (range + 1);
				mob_target((struct mob_data *)bl,src,range);
			}
		}
		break;

	case CR_DEVOTION:		/* �f�B�{�[�V���� */
		if(sd && dstsd){
			//�]����{�q�̏ꍇ�̌��̐E�Ƃ��Z�o����
			struct pc_base_job dst_s_class = pc_calc_base_job(dstsd->status.class);

			int lv = sd->status.base_level-dstsd->status.base_level;
			lv = (lv<0)?-lv:lv;
			if((dstsd->bl.type!=BL_PC)	// �����PC����Ȃ��Ƃ���
			 ||(sd->bl.id == dstsd->bl.id)	// ���肪�����͂���
			 ||(lv > 10)			// ���x�����}10�܂�
			 ||(!sd->status.party_id && !sd->status.guild_id)	// PT�ɂ��M���h�ɂ����������͂���
			 ||((sd->status.party_id != dstsd->status.party_id)	// �����p�[�e�B�[���A
			  ||(sd->status.guild_id != dstsd->status.guild_id))	// �����M���h����Ȃ��Ƃ���
			 ||(dst_s_class.job==14||dst_s_class.job==21)){	// �N���Z����
				clif_skill_fail(sd,skillid,0,0);
				map_freeblock_unlock();
				return 1;
			}
			for(i=0;i<skilllv;i++){
				if(!sd->dev.val1[i]){		// �󂫂�������������
					sd->dev.val1[i] = bl->id;
					sd->dev.val2[i] = bl->id;
					break;
				}else if(i==skilllv-1){		// �󂫂��Ȃ�����
					clif_skill_fail(sd,skillid,0,0);
					map_freeblock_unlock();
					return 1;
				}
			}
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			clif_devotion(sd,bl->id);
			skill_status_change_start(bl,SkillStatusChangeTable[skillid],src->id,1,0,0,1000*(15+15*skilllv),0 );
		}
		else	clif_skill_fail(sd,skillid,0,0);
		break;
	case MO_CALLSPIRITS:	// �C��
		if(sd) {
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			pc_addspiritball(sd,skill_get_time(skillid,skilllv),skilllv);
		}
		break;
	case MO_BLADESTOP:	// ���n���
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		skill_status_change_start(src,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0 );
		break;
	case MO_ABSORBSPIRITS:	// �C�D
		if(sd && dstsd) {
			if(sd == dstsd || map[sd->bl.m].flag.pvp || map[sd->bl.m].flag.gvg) {
				if(dstsd->spiritball > 0) {
					clif_skill_nodamage(src,bl,skillid,skilllv,1);
					i = dstsd->spiritball * 7;
					pc_delspiritball(dstsd,dstsd->spiritball,0);
					if(i > 0x7FFF)
						i = 0x7FFF;
					if(sd->status.sp + i > sd->status.max_sp) {
						i = sd->status.max_sp - sd->status.sp;
						sd->status.sp = sd->status.max_sp;
					}
					else
						sd->status.sp += i;
					clif_heal(sd->fd,SP_SP,i);
				}
				else
					clif_skill_nodamage(src,bl,skillid,skilllv,0);
			}
			else
				clif_skill_nodamage(src,bl,skillid,skilllv,0);
		}
		break;

	case AC_MAKINGARROW:			/* ��쐬 */
		if(sd) {
			clif_arrow_create_list(sd);
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
		}
		break;

	case AM_PHARMACY:			/* �|�[�V�����쐬 */
		if(sd) {
			clif_skill_produce_mix_list(sd,32);
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
		}
		break;

	case BS_HAMMERFALL:		/* �n���}�[�t�H�[�� */
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_weapon_damage )
			break;
		if( rand()%100 < (20+ 10*skilllv)*sc_def_vit/100 ) {
			skill_status_change_start(bl,SC_STAN,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		}
		break;

	case RG_RAID:			/* �T�v���C�Y�A�^�b�N */
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		{
			int x=bl->x,y=bl->y;
			skill_area_temp[1]=bl->id;
			skill_area_temp[2]=x;
			skill_area_temp[3]=y;
			map_foreachinarea(skill_area_sub,
				bl->m,x-1,y-1,x+1,y+1,0,
				src,skillid,skilllv,tick, flag|BCT_ENEMY|1,
				skill_castend_damage_id);
		}
		skill_status_change_end(src, SC_HIDING, -1);	// �n�C�f�B���O����
		break;

	case KN_BRANDISHSPEAR:	/*�u�����f�B�b�V���X�s�A*/
		{
			int c,n=4,ar;
			int dir = map_calc_dir(src,bl->x,bl->y);
			struct square tc;
			int x=bl->x,y=bl->y;
			ar=skilllv/3;
			skill_brandishspear_first(&tc,dir,x,y);
			skill_brandishspear_dir(&tc,dir,4);
			/* �͈͇C */
			if(skilllv == 10){
				for(c=1;c<4;c++){
					map_foreachinarea(skill_area_sub,
						bl->m,tc.val1[c],tc.val2[c],tc.val1[c],tc.val2[c],0,
						src,skillid,skilllv,tick, flag|BCT_ENEMY|n,
						skill_castend_damage_id);
				}
			}
			/* �͈͇B�A */
			if(skilllv > 6){
				skill_brandishspear_dir(&tc,dir,-1);
				n--;
			}else{
				skill_brandishspear_dir(&tc,dir,-2);
				n-=2;
			}

			if(skilllv > 3){
				for(c=0;c<5;c++){
					map_foreachinarea(skill_area_sub,
						bl->m,tc.val1[c],tc.val2[c],tc.val1[c],tc.val2[c],0,
						src,skillid,skilllv,tick, flag|BCT_ENEMY|n,
						skill_castend_damage_id);
					if(skilllv > 6 && n==3 && c==4){
						skill_brandishspear_dir(&tc,dir,-1);
						n--;c=-1;
					}
				}
			}
			/* �͈͇@ */
			for(c=0;c<10;c++){
				if(c==0||c==5) skill_brandishspear_dir(&tc,dir,-1);
				map_foreachinarea(skill_area_sub,
					bl->m,tc.val1[c%5],tc.val2[c%5],tc.val1[c%5],tc.val2[c%5],0,
					src,skillid,skilllv,tick, flag|BCT_ENEMY|1,
					skill_castend_damage_id);
			}
		}
		break;

	/* �p�[�e�B�X�L�� */
	case AL_ANGELUS:		/* �G���W�F���X */
	case PR_MAGNIFICAT:		/* �}�O�j�t�B�J�[�g */
	case PR_GLORIA:			/* �O�����A */
		if(sd == NULL || sd->status.party_id==0 || (flag&1) ){
			/* �ʂ̏��� */
			clif_skill_nodamage(bl,bl,skillid,skilllv,1);
			if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
				break;
			skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0);
		}
		else{
			/* �p�[�e�B�S�̂ւ̏��� */
			party_foreachsamemap(skill_area_sub,
				sd,1,
				src,skillid,skilllv,tick, flag|BCT_PARTY|1,
				skill_castend_nodamage_id);
		}
		break;
	case BS_ADRENALINE:		/* �A�h���i�������b�V�� */
	case BS_WEAPONPERFECT:	/* �E�F�|���p�[�t�F�N�V���� */
	case BS_OVERTHRUST:		/* �I�[�o�[�g���X�g */
		if(sd == NULL || sd->status.party_id==0 || (flag&1) ){
			/* �ʂ̏��� */
			clif_skill_nodamage(bl,bl,skillid,skilllv,1);
			skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,(src == bl)? 1:0,0,0,skill_get_time(skillid,skilllv),0);
		}
		else{
			/* �p�[�e�B�S�̂ւ̏��� */
			party_foreachsamemap(skill_area_sub,
				sd,1,
				src,skillid,skilllv,tick, flag|BCT_PARTY|1,
				skill_castend_nodamage_id);
		}
		break;

	/*�i�t���Ɖ������K�v�j */
	case BS_MAXIMIZE:		/* �}�L�V�}�C�Y�p���[ */
	case NV_TRICKDEAD:		/* ���񂾂ӂ� */
	case CR_DEFENDER:		/* �f�B�t�F���_�[ */
	case CR_AUTOGUARD:		/* �I�[�g�K�[�h */
		{
			int sc=SkillStatusChangeTable[skillid];
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			if( (battle_get_sc_data(bl))[sc].timer==-1 )
				/* �t������ */
				skill_status_change_start(bl,sc,skilllv,0,0,0,skill_get_time(skillid,skilllv),0);
			else
				/* �������� */
				skill_status_change_end(bl, sc, -1);
		}
		break;

	case TF_HIDING:			/* �n�C�f�B���O */
		{
			int sc=SkillStatusChangeTable[skillid];
			clif_skill_nodamage(src,bl,skillid,-1,1);
			if( (battle_get_sc_data(bl))[sc].timer==-1 )
				/* �t������ */
				skill_status_change_start(bl,sc,skilllv,0,0,0,skill_get_time(skillid,skilllv),0);
			else
				/* �������� */
				skill_status_change_end(bl, sc, -1);
		}
		break;

	case AS_CLOAKING:		/* �N���[�L���O */
		{
			int sc=SkillStatusChangeTable[skillid];
			clif_skill_nodamage(src,bl,skillid,-1,1);
			if( (battle_get_sc_data(bl))[sc].timer==-1 )
				/* �t������ */
				skill_status_change_start(bl,sc,skilllv,0,0,0,skill_get_time(skillid,skilllv),0);
			else
				/* �������� */
				skill_status_change_end(bl, sc, -1);

			skill_check_cloaking(bl);
		}
		break;

	/* �Βn�X�L�� */
	case BD_LULLABY:			/* �q��S */
	case BD_RICHMANKIM:			/* �j�����h�̉� */
	case BD_ETERNALCHAOS:		/* �i���̍��� */
	case BD_DRUMBATTLEFIELD:	/* �푾�ۂ̋��� */
	case BD_RINGNIBELUNGEN:		/* �j�[�x�����O�̎w�� */
	case BD_ROKISWEIL:			/* ���L�̋��� */
	case BD_INTOABYSS:			/* �[���̒��� */
	case BD_SIEGFRIED:			/* �s���g�̃W�[�N�t���[�h */
	case BA_DISSONANCE:			/* �s���a�� */
	case BA_POEMBRAGI:			/* �u���M�̎� */
	case BA_WHISTLE:			/* ���J */
	case BA_ASSASSINCROSS:		/* �[�z�̃A�T�V���N���X */
	case BA_APPLEIDUN:			/* �C�h�D���̗ь� */
	case DC_UGLYDANCE:			/* ��������ȃ_���X */
	case DC_HUMMING:			/* �n�~���O */
	case DC_DONTFORGETME:		/* ����Y��Ȃ��Łc */
	case DC_FORTUNEKISS:		/* �K�^�̃L�X */
	case DC_SERVICEFORYOU:		/* �T�[�r�X�t�H�[���[ */
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		skill_unitsetting(src,skillid,skilllv,src->x,src->y,0);
		break;

	case BD_ADAPTATION:			/* �A�h���u */
		{
			struct status_change *sc_data = battle_get_sc_data(src);
			if(sc_data && sc_data[SC_DANCING].timer!=-1){
				clif_skill_nodamage(src,bl,skillid,skilllv,1);
				skill_stop_dancing(src);
			}
		}
		break;

	case BA_FROSTJOKE:			/* �����W���[�N */
	case DC_SCREAM:				/* �X�N���[�� */
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		skill_addtimerskill(src,tick+3000,bl->id,0,0,skillid,skilllv,0,flag);
		break;

	case TF_STEAL:			// �X�e�B�[��
		if(sd) {
			if(pc_steal_item(sd,bl))
				clif_skill_nodamage(src,bl,skillid,skilllv,1);
			else
				clif_skill_nodamage(src,bl,skillid,skilllv,0);
		}
		break;

	case RG_STEALCOIN:		// �X�e�B�[���R�C��
	if(sd) {
			if(pc_steal_coin(sd,bl)) {
				int range = skill_get_range(skillid,skilllv);
				if(range < 0)
					range = battle_get_range(src) - (range + 1);
				clif_skill_nodamage(src,bl,skillid,skilllv,1);
				mob_target((struct mob_data *)bl,src,range);
			}
			else
				clif_skill_nodamage(src,bl,skillid,skilllv,0);
		}
		break;

	case MG_STONECURSE:			/* �X�g�[���J�[�X */
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
			break;
		if( rand()%100 < skilllv*4+20 )
			skill_status_change_start(bl,SC_STONE,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		else if(sd)
			clif_skill_fail(sd,skillid,0,0);
		break;

	case NV_FIRSTAID:			/* ���}�蓖 */
		clif_skill_nodamage(src,bl,skillid,5,1);
		battle_heal(NULL,bl,5,0,0);
		break;

	case AL_CURE:				/* �L���A�[ */
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
			break;
		skill_status_change_end(bl, SC_SILENCE	, -1 );
		skill_status_change_end(bl, SC_BLIND	, -1 );
		skill_status_change_end(bl, SC_CONFUSION, -1 );
		break;

	case TF_DETOXIFY:			/* ��� */
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		skill_status_change_end(bl, SC_POISON	, -1 );
		break;

	case PR_STRECOVERY:			/* ���J�o���[ */
		{
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
				break;
			skill_status_change_end(bl, SC_FREEZE	, -1 );
			skill_status_change_end(bl, SC_STONE	, -1 );
			skill_status_change_end(bl, SC_SLEEP	, -1 );
			skill_status_change_end(bl, SC_STAN		, -1 );
			if( battle_check_undead(battle_get_race(bl),battle_get_elem_type(bl)) ){//�A���f�b�h�Ȃ�ÈŌ���
				int blind_time;
				//blind_time=30-battle_get_vit(bl)/10-battle_get_int/15;
				blind_time=30*(100-(battle_get_int(bl)+battle_get_vit(bl))/2)/100;
				if(rand()%100 < (100-(battle_get_int(bl)/2+battle_get_vit(bl)/3+battle_get_luk(bl)/10)))
					skill_status_change_start(bl, SC_BLIND,1,0,0,0,blind_time,0);
			}
			if(dstmd){
				dstmd->attacked_id=0;
				dstmd->target_id=0;
				dstmd->state.targettype = NONE_ATTACKABLE;
				dstmd->state.skillstate=MSS_IDLE;
				dstmd->next_walktime=tick+rand()%3000+3000;
			}
		}
		break;

	case WZ_ESTIMATION:			/* �����X�^�[��� */
		if(src->type==BL_PC){
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			clif_skill_estimation((struct map_session_data *)src,bl);
		}
		break;

	case MC_IDENTIFY:			/* �A�C�e���Ӓ� */
		if(sd)
			clif_item_identify_list(sd);
		break;

	case MC_VENDING:			/* �I�X�J�� */
		if(sd)
			clif_openvendingreq(sd,2+sd->skilllv);
		break;

	case AL_TELEPORT:			/* �e���|�[�g */
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if( sd ){
			if(map[sd->bl.m].flag.noteleport)	/* �e���|�֎~ */
				break;
			if( sd->skilllv==1 )
				clif_skill_warppoint(sd,sd->skillid,"Random","","","");
			else{
				clif_skill_warppoint(sd,sd->skillid,"Random",
					sd->status.save_point.map,"","");
			}
		}else if( bl->type==BL_MOB )
			mob_warp((struct mob_data *)bl,-1,-1,-1,3);
		break;

	case AL_HOLYWATER:			/* �A�N�A�x�l�f�B�N�^ */
		if(sd) {
			int eflag;
			struct item item_tmp;
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			memset(&item_tmp,0,sizeof(item_tmp));
			item_tmp.nameid = 523;
			item_tmp.identify = 1;
			if(battle_config.holywater_name_input) {
				item_tmp.card[0] = 0xfe;
				item_tmp.card[1] = 0;
				*((unsigned long *)(&item_tmp.card[2]))=sd->char_id;	/* �L����ID */
			}
			eflag = pc_additem(sd,&item_tmp,1);
			if(eflag) {
				clif_additem(sd,0,0,eflag);
				map_addflooritem(&item_tmp,1,sd->bl.m,sd->bl.x,sd->bl.y,NULL,NULL,NULL,0);
			}
		}
		break;
	case TF_PICKSTONE:
		if(sd) {
			int eflag;
			struct item item_tmp;
			struct block_list tbl;
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			memset(&item_tmp,0,sizeof(item_tmp));
			item_tmp.nameid = 7049;
			item_tmp.identify = 1;
			tbl.id = 0;
			clif_takeitem(&sd->bl,&tbl);
			eflag = pc_additem(sd,&item_tmp,1);
			if(eflag) {
				clif_additem(sd,0,0,eflag);
				map_addflooritem(&item_tmp,1,sd->bl.m,sd->bl.x,sd->bl.y,NULL,NULL,NULL,0);
			}
		}
		break;

	case RG_STRIPWEAPON:		/* �X�g���b�v�E�F�|�� */
		if( (battle_get_sc_data(bl))[SC_CP_WEAPON].timer != -1 )
			break;
		strip_per = 5+2*skilllv+strip_fix/5;
		strip_time = skill_get_time(skillid,skilllv)+strip_fix/2;
		if(rand()%100 < strip_per){
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,strip_time,0 );
			if(dstsd){
				for(i=0;i<MAX_INVENTORY;i++){
					if(dstsd->status.inventory[i].equip && dstsd->status.inventory[i].equip & 0x0002){
						pc_unequipitem(dstsd,i,0);
						break;
					}
				}
			}
		}
		break;

	case RG_STRIPSHIELD:		/* �X�g���b�v�V�[���h */
		if( (battle_get_sc_data(bl))[SC_CP_SHIELD].timer != -1 )
			break;
		strip_per = 5+2*skilllv+strip_fix/5;
		strip_time = skill_get_time(skillid,skilllv)+strip_fix/2;
		if(rand()%100 < strip_per){
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,strip_time,0 );
			if(dstsd){
				for(i=0;i<MAX_INVENTORY;i++){
					if(dstsd->status.inventory[i].equip && dstsd->status.inventory[i].equip & 0x0020){
						pc_unequipitem(dstsd,i,0);
						break;
					}
				}
			}
		}
		break;
	case RG_STRIPARMOR:			/* �X�g���b�v�A�[�}�[ */
		if( (battle_get_sc_data(bl))[SC_CP_ARMOR].timer != -1 )
			break;
		strip_per = 5+2*skilllv+strip_fix/5;
		strip_time = skill_get_time(skillid,skilllv)+strip_fix/2;
		if(rand()%100 < strip_per){
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,strip_time,0 );
			if(dstsd){
				for(i=0;i<MAX_INVENTORY;i++){
					if(dstsd->status.inventory[i].equip && dstsd->status.inventory[i].equip & 0x0010){
						pc_unequipitem(dstsd,i,0);
						break;
					}
				}
			}
		}
		break;
	case RG_STRIPHELM:			/* �X�g���b�v�w���� */
		if( (battle_get_sc_data(bl))[SC_CP_HELM].timer != -1 )
			break;
		strip_per = 5+2*skilllv+strip_fix/5;
		strip_time = skill_get_time(skillid,skilllv)+strip_fix/2;
		if(rand()%100 < strip_per){
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,strip_time,0 );
			if(dstsd){
				for(i=0;i<MAX_INVENTORY;i++){
					if(dstsd->status.inventory[i].equip && dstsd->status.inventory[i].equip & 0x0100){
						pc_unequipitem(dstsd,i,0);
						break;
					}
				}
			}
		}
		break;
	/* PotionPitcher */
	case AM_POTIONPITCHER:		/* �|�[�V�����s�b�`���[ */
		{
			struct block_list tbl;
			int i,x,hp = 0,sp = 0;
			if(sd) {
				x = skilllv%11 - 1;
				i = pc_search_inventory(sd,skill_db[skillid].itemid[x]);
				if(i < 0 || skill_db[skillid].itemid[x] <= 0) {
					clif_skill_fail(sd,skillid,0,0);
					map_freeblock_unlock();
					return 1;
				}
				if(sd->inventory_data[i] == NULL || sd->status.inventory[i].amount < skill_db[skillid].amount[x]) {
					clif_skill_fail(sd,skillid,0,0);
					map_freeblock_unlock();
					return 1;
				}
				sd->state.potionpitcher_flag = 1;
				sd->potion_hp = sd->potion_sp = sd->potion_per_hp = sd->potion_per_sp = 0;
				sd->skilltarget = bl->id;
				run_script(sd->inventory_data[i]->use_script,0,sd->bl.id,0);
				pc_delitem(sd,i,skill_db[skillid].amount[x],0);
				sd->state.potionpitcher_flag = 0;
				if(sd->potion_per_hp > 0 || sd->potion_per_sp > 0) {
					hp = battle_get_max_hp(bl) * sd->potion_per_hp / 100;
					hp = hp * (100 + pc_checkskill(sd,AM_POTIONPITCHER)*10 + pc_checkskill(sd,AM_LEARNINGPOTION)*5)/100;
					if(dstsd) {
						sp = dstsd->status.max_sp * sd->potion_per_sp / 100;
						sp = sp * (100 + pc_checkskill(sd,AM_POTIONPITCHER) + pc_checkskill(sd,AM_LEARNINGPOTION)*5)/100;
					}
				}
				else {
					if(sd->potion_hp > 0) {
						hp = sd->potion_hp * (100 + pc_checkskill(sd,AM_POTIONPITCHER)*10 + pc_checkskill(sd,AM_LEARNINGPOTION)*5)/100;
						hp = hp * (100 + (battle_get_vit(bl)<<1)) / 100;
						if(dstsd)
							hp = hp * (100 + pc_checkskill(dstsd,SM_RECOVERY)*10) / 100;
					}
					if(sd->potion_sp > 0) {
						sp = sd->potion_sp * (100 + pc_checkskill(sd,AM_POTIONPITCHER) + pc_checkskill(sd,AM_LEARNINGPOTION)*5)/100;
						sp = sp * (100 + (battle_get_int(bl)<<1)) / 100;
						if(dstsd)
							sp = sp * (100 + pc_checkskill(dstsd,MG_SRECOVERY)*10) / 100;
					}
				}
			}
			else {
				hp = (1 + rand()%400) * (100 + skilllv*10) / 100;
				hp = hp * (100 + (battle_get_vit(bl)<<1)) / 100;
				if(dstsd)
					hp = hp * (100 + pc_checkskill(dstsd,SM_RECOVERY)*10) / 100;
			}
			tbl.id = 0;
			tbl.m = src->m;
			tbl.x = src->x;
			tbl.y = src->y;
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			if(hp > 0 || (hp <= 0 && sp <= 0))
				clif_skill_nodamage(&tbl,bl,AL_HEAL,hp,1);
			if(sp > 0)
				clif_skill_nodamage(&tbl,bl,MG_SRECOVERY,sp,1);
			battle_heal(src,bl,hp,sp,0);
		}
		break;
	case AM_CP_WEAPON:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if((battle_get_sc_data(bl))[SC_STRIPWEAPON].timer != -1)
			skill_status_change_end(bl, SC_STRIPWEAPON, -1 );
		skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0 );
		break;
	case AM_CP_SHIELD:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if((battle_get_sc_data(bl))[SC_STRIPSHIELD].timer != -1)
			skill_status_change_end(bl, SC_STRIPSHIELD, -1 );
		skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0 );
		break;
	case AM_CP_ARMOR:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if((battle_get_sc_data(bl))[SC_STRIPARMOR].timer != -1)
			skill_status_change_end(bl, SC_STRIPARMOR, -1 );
		skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0 );
		break;
	case AM_CP_HELM:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if((battle_get_sc_data(bl))[SC_STRIPHELM].timer != -1)
			skill_status_change_end(bl, SC_STRIPHELM, -1 );
		skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0 );
		break;
	case SA_DISPELL:			/* �f�B�X�y�� */
		{
			int i;
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
				break;
			for(i=0;i<136;i++){
				if(i==SC_RIDING || i== SC_FALCON || i==SC_HALLUCINATION || i==SC_WEIGHT50
					|| i==SC_WEIGHT90 || i==SC_STRIPWEAPON || i==SC_STRIPSHIELD || i==SC_STRIPARMOR
					|| i==SC_STRIPHELM || i==SC_CP_WEAPON || i==SC_CP_SHIELD || i==SC_CP_ARMOR
					|| i==SC_CP_HELM || i==SC_COMBO)
						continue;
				skill_status_change_end(bl,i,-1);
			}
		}
		break;

	case TF_BACKSLIDING:		/* �o�b�N�X�e�b�v */
		battle_stopwalking(src,1);
		skill_blown(src,bl,skill_get_blewcount(skillid,skilllv)|0x10000);
		if(src->type == BL_MOB)
			clif_fixmobpos((struct mob_data *)src);
		else if(src->type == BL_PET)
			clif_fixpetpos((struct pet_data *)src);
		else if(src->type == BL_PC)
			clif_fixpos(src);
		skill_addtimerskill(src,tick + 200,src->id,0,0,skillid,skilllv,0,flag);
		break;

	case SA_CASTCANCEL:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		skill_castcancel(src,1);
		if(sd) {
			int sp = skill_get_sp(sd->skillid_old,sd->skilllv_old);
			sp = sp * (90 - (skilllv-1)*20) / 100;
			if(sp < 0) sp = 0;
			pc_heal(sd,0,-sp);
		}
		break;
	case SA_SPELLBREAKER:	// �X�y���u���C�J�[
		{
			struct status_change *sc_data = battle_get_sc_data(bl);
			int sp;
			if(sc_data && sc_data[SC_MAGICROD].timer != -1) {
				if(dstsd) {
					sp = skill_get_sp(skillid,skilllv);
					sp = sp * sc_data[SC_MAGICROD].val2 / 100;
					if(sp > 0x7fff) sp = 0x7fff;
					else if(sp < 1) sp = 1;
					if(dstsd->status.sp + sp > dstsd->status.max_sp) {
						sp = dstsd->status.max_sp - dstsd->status.sp;
						dstsd->status.sp = dstsd->status.max_sp;
					}
					else
						dstsd->status.sp += sp;
					clif_heal(dstsd->fd,SP_SP,sp);
				}
				clif_skill_nodamage(bl,bl,SA_MAGICROD,sc_data[SC_MAGICROD].val1,1);
				if(sd) {
					sp = sd->status.max_sp/5;
					if(sp < 1) sp = 1;
					pc_heal(sd,0,-sp);
				}
			}
			else {
				int bl_skillid=0,bl_skilllv=0;
				if(bl->type == BL_PC) {
					if(dstsd->skilltimer != -1) {
						bl_skillid = dstsd->skillid;
						bl_skilllv = dstsd->skilllv;
					}
				}
				else if(bl->type == BL_MOB) {
					if(dstmd->skilltimer != -1) {
						bl_skillid = dstmd->skillid;
						bl_skilllv = dstmd->skilllv;
					}
				}
				if(bl_skillid > 0 && skill_db[bl_skillid].skill_type == BF_MAGIC) {
					clif_skill_nodamage(src,bl,skillid,skilllv,1);
					skill_castcancel(bl,0);
					sp = skill_get_sp(bl_skillid,bl_skilllv);
					if(dstsd)
						pc_heal(dstsd,0,-sp);
					if(sd) {
						sp = sp*(25*(skilllv-1))/100;
						if(skilllv > 1 && sp < 1) sp = 1;
						if(sp > 0x7fff) sp = 0x7fff;
						else if(sp < 1) sp = 1;
						if(sd->status.sp + sp > sd->status.max_sp) {
							sp = sd->status.max_sp - sd->status.sp;
							sd->status.sp = sd->status.max_sp;
						}
						else
							sd->status.sp += sp;
						clif_heal(sd->fd,SP_SP,sp);
					}
				}
				else if(sd)
					clif_skill_fail(sd,skillid,0,0);
			}
		}
		break;
	case SA_MAGICROD:
		if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
			break;
		skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0 );
		break;
	case SA_AUTOSPELL:			/* �I�[�g�X�y�� */
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if(sd)
			clif_autospell(sd,skilllv);
		else {
			int maxlv=1,spellid=0;
			static const int spellarray[3] = { MG_COLDBOLT,MG_FIREBOLT,MG_LIGHTNINGBOLT };
			if(skilllv >= 10) {
				spellid = MG_FROSTDIVER;
				maxlv = skilllv - 9;
			}
			else if(skilllv >=8) {
				spellid = MG_FIREBALL;
				maxlv = skilllv - 7;
			}
			else if(skilllv >=5) {
				spellid = MG_SOULSTRIKE;
				maxlv = skilllv - 4;
			}
			else if(skilllv >=2) {
				int i = rand()%3;
				spellid = spellarray[i];
				maxlv = skilllv - 1;
			}
			else if(skilllv > 0) {
				spellid = MG_NAPALMBEAT;
				maxlv = 3;
			}
			if(spellid > 0)
				skill_status_change_start(src,SC_AUTOSPELL,skilllv,spellid,maxlv,0,
					skill_get_time(SA_AUTOSPELL,skilllv),0);
		}
		break;

	/* �����_�������ω��A�������ω��A�n�A�΁A�� */
	case NPC_ATTRICHANGE:
	case NPC_CHANGEWATER:
	case NPC_CHANGEGROUND:
	case NPC_CHANGEFIRE:
	case NPC_CHANGEWIND:
	/* �ŁA���A�O�A�� */
	case NPC_CHANGEPOISON:
	case NPC_CHANGEHOLY:
	case NPC_CHANGEDARKNESS:
	case NPC_CHANGETELEKINESIS:
		if(md){
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			md->def_ele=skill_get_pl(skillid);
			if(md->def_ele==0)			/* �����_���ω��A�������A*/
				md->def_ele=rand()%10;	/* �s�������͏��� */
			md->def_ele+=(1+rand()%4)*20;	/* �������x���̓����_�� */
		}
		break;

	case NPC_PROVOCATION:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if(md)
			clif_pet_performance(src,mob_db[md->class].skill[md->skillidx].val[0]);
		break;

	case NPC_HALLUCINATION:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
			break;
		skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_get_time(skillid,skilllv),0 );
		break;

	case NPC_KEEPING:
	case NPC_BARRIER:
		{
			int skill_time = skill_get_time(skillid,skilllv);
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			skill_status_change_start(bl,SkillStatusChangeTable[skillid],skilllv,0,0,0,skill_time,0 );
			mob_changestate((struct mob_data *)src,MS_DELAY,skill_time);
		}
		break;

	case NPC_DARKBLESSING:
		{
			int sc_def = 100 - battle_get_mdef(bl);
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
				break;
			if(battle_get_elem_type(bl) == 7 || battle_get_race(bl) == 6)
				break;
			if(rand()%100 < sc_def*(50+skilllv*5)/100) {
				if(dstsd) {
					int hp = battle_get_hp(bl)-1;
					pc_heal(dstsd,-hp,0);
				}
				else if(dstmd)
					dstmd->hp = 1;
			}
		}
		break;

	case NPC_LICK:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_weapon_damage )
			break;
		if(dstsd)
			pc_heal(dstsd,0,-100);
		if(rand()%100 < (skilllv*5)*sc_def_vit/100)
			skill_status_change_start(bl,SC_STAN,skilllv,0,0,0,skill_get_time2(skillid,skilllv),0);
		break;

	case NPC_SUICIDE:			/* ���� */
		if(md){
			clif_skill_nodamage(src,bl,skillid,skilllv,1);
			mob_damage(NULL,md,md->hp,0);
		}
		break;

	case NPC_SUMMONSLAVE:		/* �艺���� */
	case NPC_SUMMONMONSTER:		/* MOB���� */
		if(md && !md->master_id){
			mob_summonslave(md,mob_db[md->class].skill[md->skillidx].val,skilllv,(skillid==NPC_SUMMONSLAVE)?1:0);
		}
		break;

	case NPC_TRANSFORMATION:
	case NPC_METAMORPHOSIS:
		if(md)
			mob_class_change(md,mob_db[md->class].skill[md->skillidx].val);
		break;

	case NPC_EMOTION:			/* �G���[�V���� */
		if(md)
			clif_emotion(&md->bl,mob_db[md->class].skill[md->skillidx].val[0]);
		break;

	case NPC_DEFENDER:
		clif_skill_nodamage(src,bl,skillid,skilllv,1);
		break;

	default:
		map_freeblock_unlock();
		return 1;
	}

	map_freeblock_unlock();
	return 0;
}

/*==========================================
 * �X�L���g�p�i�r�������AID�w��j
 *------------------------------------------
 */
int skill_castend_id( int tid, unsigned int tick, int id,int data )
{
	struct map_session_data* sd=NULL/*,*target_sd=NULL*/;
	struct block_list *bl;
	int range,inf2;

	if( (sd=map_id2sd(id))==NULL || sd->bl.prev == NULL)
		return 0;

	if(sd->skillid != SA_CASTCANCEL && sd->skilltimer != tid )	/* �^�C�}ID�̊m�F */
		return 0;
	if(sd->skillid != SA_CASTCANCEL && sd->skilltimer != -1 && pc_checkskill(sd,SA_FREECAST) > 0) {
		sd->speed = sd->prev_speed;
		clif_updatestatus(sd,SP_SPEED);
	}
	if(sd->skillid != SA_CASTCANCEL)
		sd->skilltimer=-1;
	bl=map_id2bl(sd->skilltarget);
	if(bl==NULL || bl->prev==NULL) {
		sd->canact_tick = tick;
		sd->canmove_tick = tick;
		sd->skillitem = sd->skillitemlv = -1;
		return 0;
	}
	if(sd->bl.m != bl->m || pc_isdead(sd)) {
		sd->canact_tick = tick;
		sd->canmove_tick = tick;
		sd->skillitem = sd->skillitemlv = -1;
		return 0;
	}

	if(sd->skillid == PR_LEXAETERNA) {
		struct status_change *sc_data = battle_get_sc_data(bl);
		if(sc_data && (sc_data[SC_FREEZE].timer != -1 || (sc_data[SC_STONE].timer != -1 && sc_data[SC_STONE].val2 == 0))) {
			clif_skill_fail(sd,sd->skillid,0,0);
			sd->canact_tick = tick;
			sd->canmove_tick = tick;
			sd->skillitem = sd->skillitemlv = -1;
			return 0;
		}
	}
	else if(sd->skillid == RG_BACKSTAP) {
		int dir = map_calc_dir(&sd->bl,bl->x,bl->y),t_dir = battle_get_dir(bl);
		int dist = distance(sd->bl.x,sd->bl.y,bl->x,bl->y);
		if(bl->type != BL_SKILL && (dist == 0 || map_check_dir(dir,t_dir))) {
			clif_skill_fail(sd,sd->skillid,0,0);
			sd->canact_tick = tick;
			sd->canmove_tick = tick;
			sd->skillitem = sd->skillitemlv = -1;
			return 0;
		}
	}

	inf2 = skill_get_inf2(sd->skillid);
	if( ( (skill_get_inf(sd->skillid)&1) || inf2&4 ) &&	// �މ�G�Ί֌W�`�F�b�N
		battle_check_target(&sd->bl,bl, BCT_ENEMY)<=0 ) {
		sd->canact_tick = tick;
		sd->canmove_tick = tick;
		sd->skillitem = sd->skillitemlv = -1;
		return 0;
	}
	if(inf2 & 0xC00 && sd->bl.id != bl->id) {
		int fail_flag = 1;
		if(inf2 & 0x400 && battle_check_target(&sd->bl,bl, BCT_PARTY) > 0)
			fail_flag = 0;
		if(inf2 & 0x800 && sd->status.guild_id > 0 && sd->status.guild_id == battle_get_guild_id(bl))
			fail_flag = 0;
		if(fail_flag) {
			clif_skill_fail(sd,sd->skillid,0,0);
			sd->canact_tick = tick;
			sd->canmove_tick = tick;
			sd->skillitem = sd->skillitemlv = -1;
			return 0;
		}
	}

	range = skill_get_range(sd->skillid,sd->skilllv);
	if(range < 0)
		range = battle_get_range(&sd->bl) - (range + 1);
	range += battle_config.pc_skill_add_range;
	if(sd->skillid == MO_EXTREMITYFIST && sd->sc_data[SC_COMBO].timer != -1 && sd->sc_data[SC_COMBO].val1 == MO_COMBOFINISH)
		range += skill_get_blewcount(MO_COMBOFINISH,sd->sc_data[SC_COMBO].val2);
	if(!battle_config.skill_out_range_consume) {
		if(range < distance(sd->bl.x,sd->bl.y,bl->x,bl->y)) {
			clif_skill_fail(sd,sd->skillid,0,0);
			sd->canact_tick = tick;
			sd->canmove_tick = tick;
			sd->skillitem = sd->skillitemlv = -1;
			return 0;
		}
	}
	if(!skill_check_condition(sd,1)) {		/* �g�p�����`�F�b�N */
		sd->canact_tick = tick;
		sd->canmove_tick = tick;
		sd->skillitem = sd->skillitemlv = -1;
		return 0;
	}
	sd->skillitem = sd->skillitemlv = -1;
	if(battle_config.skill_out_range_consume) {
		if(range < distance(sd->bl.x,sd->bl.y,bl->x,bl->y)) {
			clif_skill_fail(sd,sd->skillid,0,0);
			sd->canact_tick = tick;
			sd->canmove_tick = tick;
			return 0;
		}
	}

	if(battle_config.pc_skill_log)
		printf("PC %d skill castend skill=%d\n",sd->bl.id,sd->skillid);
	pc_stop_walking(sd,0);

	switch( skill_get_nk(sd->skillid) )
	{
	/* �U���n/������΂��n */
	case 0:	case 2:
		skill_castend_damage_id(&sd->bl,bl,sd->skillid,sd->skilllv,tick,0);
		break;
	case 1:/* �x���n */
		if( (sd->skillid==AL_HEAL || (sd->skillid==ALL_RESURRECTION && bl->type != BL_PC)) && battle_check_undead(battle_get_race(bl),battle_get_elem_type(bl)))
			skill_castend_damage_id(&sd->bl,bl,sd->skillid,sd->skilllv,tick,0);
		else
			skill_castend_nodamage_id(&sd->bl,bl,sd->skillid,sd->skilllv,tick,0);
		break;
	}

	return 0;
}

/*==========================================
 * �X�L���g�p�i�r�������A�ꏊ�w��̎��ۂ̏����j
 *------------------------------------------
 */
int skill_castend_pos2( struct block_list *src, int x,int y,int skillid,int skilllv,unsigned int tick,int flag)
{
	struct map_session_data *sd=NULL;
	int i,tmpx = 0,tmpy = 0, x1 = 0, y1 = 0;

	if(src->type==BL_PC)
		sd=(struct map_session_data *)src;
	if(skillid != WZ_METEOR && skillid != WZ_SIGHTRASHER)
		clif_skill_poseffect(src,skillid,skilllv,x,y,tick);

	switch(skillid)
	{
	case PR_BENEDICTIO:			/* ���̍~�� */
		skill_area_temp[1]=src->id;
		map_foreachinarea(skill_area_sub,
			src->m,x-1,y-1,x+1,y+1,0,
			src,skillid,skilllv,tick, flag|BCT_NOENEMY|1,
			skill_castend_nodamage_id);
		map_foreachinarea(skill_area_sub,
			src->m,x-1,y-1,x+1,y+1,0,
			src,skillid,skilllv,tick, flag|BCT_ENEMY|1,
			skill_castend_damage_id);
		break;

	case BS_HAMMERFALL:			/* �n���}�[�t�H�[�� */
		skill_area_temp[1]=src->id;
		skill_area_temp[2]=x;
		skill_area_temp[3]=y;
		map_foreachinarea(skill_area_sub,
			src->m,x-2,y-2,x+2,y+2,0,
			src,skillid,skilllv,tick, flag|BCT_ENEMY|2,
			skill_castend_nodamage_id);
		break;

	case MG_SAFETYWALL:			/* �Z�C�t�e�B�E�H�[�� */
	case MG_FIREWALL:			/* �t�@�C���[�E�H�[�� */
	case MG_THUNDERSTORM:		/* �T���_�[�X�g�[�� */
	case AL_PNEUMA:				/* �j���[�} */
	case WZ_ICEWALL:			/* �A�C�X�E�H�[�� */
	case WZ_FIREPILLAR:			/* �t�@�C�A�s���[ */
	case WZ_SIGHTRASHER:
	case WZ_QUAGMIRE:			/* �N�@�O�}�C�A */
	case WZ_VERMILION:			/* ���[�h�I�u���@�[�~���I�� */
	case WZ_FROSTNOVA:			/* �t���X�g�m���@ */
	case WZ_STORMGUST:			/* �X�g�[���K�X�g */
	case WZ_HEAVENDRIVE:		/* �w�����Y�h���C�u */
	case PR_SANCTUARY:			/* �T���N�`���A�� */
	case PR_MAGNUS:				/* �}�O�k�X�G�N�\�V�Y�� */
	case CR_GRANDCROSS:			/* �O�����h�N���X */
	case HT_SKIDTRAP:			/* �X�L�b�h�g���b�v */
	case HT_LANDMINE:			/* �����h�}�C�� */
	case HT_ANKLESNARE:			/* �A���N���X�l�A */
	case HT_SHOCKWAVE:			/* �V���b�N�E�F�[�u�g���b�v */
	case HT_SANDMAN:			/* �T���h�}�� */
	case HT_FLASHER:			/* �t���b�V���[ */
	case HT_FREEZINGTRAP:		/* �t���[�W���O�g���b�v */
	case HT_BLASTMINE:			/* �u���X�g�}�C�� */
	case HT_CLAYMORETRAP:		/* �N���C���A�[�g���b�v */
	case AS_VENOMDUST:			/* �x�m���_�X�g */
	case AM_DEMONSTRATION:			/* �f�����X�g���[�V���� */
		skill_unitsetting(src,skillid,skilllv,x,y,0);
		break;

	case SA_VOLCANO:		/* �{���P�[�m */
	case SA_DELUGE:			/* �f�����[�W */
	case SA_VIOLENTGALE:	/* �o�C�I�����g�Q�C�� */
	case SA_LANDPROTECTOR:	/* �����h�v���e�N�^�[ */
		skill_clear_element_field(src);//���Ɏ������������Ă��鑮������N���A
		skill_unitsetting(src,skillid,skilllv,x,y,0);
		break;

	case WZ_METEOR:				//���e�I�X�g�[��
		{
			int flag=0;
			for(i=0;i<2+(skilllv>>1);i++) {
				int j=0, c;
				do {
					tmpx = x + (rand()%7 - 3);
					tmpy = y + (rand()%7 - 3);
					if(tmpx < 0)
						tmpx = 0;
					else if(tmpx >= map[src->m].xs)
						tmpx = map[src->m].xs - 1;
					if(tmpy < 0)
						tmpy = 0;
					else if(tmpy >= map[src->m].ys)
						tmpy = map[src->m].ys - 1;
					j++;
				} while(((c=map_getcell(src->m,tmpx,tmpy))==1 || c==5) && j<100);
				if(j >= 100)
					continue;
				if(flag==0){
					clif_skill_poseffect(src,skillid,skilllv,tmpx,tmpy,tick);
					flag=1;
				}
				if(i > 0)
					skill_addtimerskill(src,tick+i*1000,0,tmpx,tmpy,skillid,skilllv,(x1<<16)|y1,flag);
				x1 = tmpx;
				y1 = tmpy;
			}
			skill_addtimerskill(src,tick+i*1000,0,tmpx,tmpy,skillid,skilllv,-1,flag);
		}
		break;

	case AL_WARP:				/* ���[�v�|�[�^�� */
		if(sd) {
			if(map[sd->bl.m].flag.noteleport)	/* �e���|�֎~ */
				break;
			clif_skill_warppoint(sd,sd->skillid,sd->status.save_point.map,
				(sd->skilllv>1)?sd->status.memo_point[0].map:"",
				(sd->skilllv>2)?sd->status.memo_point[1].map:"",
				(sd->skilllv>3)?sd->status.memo_point[2].map:"");
		}
		break;
	case MO_BODYRELOCATION:
		if(sd){
			pc_movepos(sd,x,y);
		}else if( src->type==BL_MOB )
			mob_warp((struct mob_data *)src,-1,x,y,0);
		break;
	case AM_CANNIBALIZE:	// �o�C�I�v�����g
		if(sd){
			int mx,my,id=0;
			struct mob_data *md;

			mx = x + (rand()%10 - 5);
			my = y + (rand()%10 - 5);
			id=mob_once_spawn(sd,"this",mx,my,"--ja--",1118,1,"");
			if( (md=(struct mob_data *)map_id2bl(id)) !=NULL ){
				mob_exclusion_add(md,1,sd->bl.id);
				md->master_id=sd->bl.id;
				md->hp=2210+skilllv*200;
				md->state.special_mob_ai=1;
				add_timer(gettick()+30000+skilllv*10000,mob_timer_delete,id,0);
			}
		}
		break;
	case AM_SPHEREMINE:	// �X�t�B�A�[�}�C��
		if(sd){
			int mx,my,id=0;
			struct mob_data *md;

			mx = x + (rand()%10 - 5);
			my = y + (rand()%10 - 5);
			id=mob_once_spawn(sd,"this",mx,my,"--ja--",1142,1,"");
			if( (md=(struct mob_data *)map_id2bl(id)) !=NULL ){
				mob_exclusion_add(md,1,sd->bl.id);
				md->master_id=sd->bl.id;
				md->hp=1000+skilllv*200;
				md->state.special_mob_ai=2;
				add_timer(gettick()+30000,mob_timer_delete,id,0);
			}
		}
		break;
	}

	return 0;
}

/*==========================================
 * �X�L���g�p�i�r�������Amap�w��j
 *------------------------------------------
 */
int skill_castend_map( struct map_session_data *sd,int skill_num, const char *map)
{
	int x=0,y=0;

	if( sd==NULL || sd->bl.prev == NULL || pc_isdead(sd))
		return 0;

	if( sd->opt1>0 || sd->status.option&2 || sd->sc_data[SC_DIVINA].timer!=-1 || sd->sc_data[SC_ROKISWEIL].timer!=-1 ||
		sd->sc_data[SC_AUTOCOUNTER].timer != -1 || sd->sc_data[SC_STEELBODY].timer != -1)
		return 0;	/* �ُ�Ⓘ�قȂ� */

	/* ���t/�_���X�����`�F�b�N */
	if( sd->sc_data[SC_DANCING].timer!=-1 )
		return 0;

	if( skill_num != sd->skillid)	/* �s���p�P�b�g�炵�� */
		return 0;

	pc_stopattack(sd);

	if(battle_config.pc_skill_log)
		printf("PC %d skill castend skill =%d map=%s\n",sd->bl.id,skill_num,map);
	pc_stop_walking(sd,0);

	if(strcmp(map,"cancel")==0)
		return 0;

	switch(skill_num){
	case AL_TELEPORT:		/* �e���|�[�g */
		if(strcmp(map,"Random")==0)
			pc_randomwarp(sd,3);
		else
			pc_setpos(sd,sd->status.save_point.map,
				sd->status.save_point.x,sd->status.save_point.y,3);
		break;

	case AL_WARP:			/* ���[�v�|�[�^�� */
		{
			const struct point *p[]={
				&sd->status.save_point,&sd->status.memo_point[0],
				&sd->status.memo_point[1],&sd->status.memo_point[2],
			};
			struct skill_unit_group *group;
			int i;
			for(i=0;i<sd->skilllv;i++){
				if(strcmp(map,p[i]->map)==0){
					x=p[i]->x;
					y=p[i]->y;
					break;
				}
			}
			if(x==0 || y==0)	/* �s���p�P�b�g�H */
				return 0;

			group=skill_unitsetting(&sd->bl,sd->skillid,sd->skilllv,sd->skillx,sd->skilly,0);
			group->valstr=calloc(24, 1);
			if(group->valstr==NULL){
				printf("skill_castend_map: out of memory !\n");
				exit(1);
			}
			memcpy(group->valstr,map,24);
			group->val2=(x<<16)|y;
		}
		break;
	}

	return 0;
}

/*==========================================
 * �X�L�����j�b�g�ݒ菈��
 *------------------------------------------
 */
struct skill_unit_group *skill_unitsetting( struct block_list *src, int skillid,int skilllv,int x,int y,int flag)
{
	struct skill_unit_group *group;
	int i,count=1,limit=10000,val1=0,val2=0;
	int target=BCT_ENEMY,interval=1000,range=0;
	int dir=0;

	switch(skillid){	/* �ݒ� */

	case MG_SAFETYWALL:			/* �Z�C�t�e�B�E�H�[�� */
		limit=skill_get_time(skillid,skilllv);
		val2=skilllv+1;
		interval = -1;
		target=(battle_config.defnotenemy)?BCT_NOENEMY:BCT_ALL;
		break;

	case MG_FIREWALL:			/* �t�@�C���[�E�H�[�� */
		if(src->x == x && src->y == y)
			dir = 2;
		else
			dir=map_calc_dir(src,x,y);
		if(dir&1) count=5;
		else count=3;
		limit=skill_get_time(skillid,skilllv);
		val2=4+skilllv;
		interval=1;
		break;

	case AL_PNEUMA:				/* �j���[�} */
		limit=skill_get_time(skillid,skilllv);
		interval = -1;
		target=(battle_config.defnotenemy)?BCT_NOENEMY:BCT_ALL;
		count = 9;
		break;

	case AL_WARP:				/* ���[�v�|�[�^�� */
		target=BCT_ALL;
		val1=skilllv+6;
		if(flag==0)
			limit=2000;
		else
			limit=skill_get_time(skillid,skilllv);
		break;

	case PR_SANCTUARY:			/* �T���N�`���A�� */
		count=21;
		limit=skill_get_time(skillid,skilllv);
		val1=skilllv+3;
		val2=(skilllv>6)?777:skilllv*100;
		target=BCT_ALL;
		range=1;
		break;

	case PR_MAGNUS:				/* �}�O�k�X�G�N�\�V�Y�� */
		count=33;
		limit=skill_get_time(skillid,skilllv);
		interval=3000;
		break;

	case WZ_FIREPILLAR:			/* �t�@�C�A�[�s���[ */
		if(flag==0)
			limit=skill_get_time(skillid,skilllv);
		else
			limit=1000;
		interval=2000;
		val1=skilllv+2;
		range=1;
		break;

	case MG_THUNDERSTORM:		/* �T���_�[�X�g�[�� */
		limit=500;
		range=1;
		break;

	case WZ_FROSTNOVA:		/* �t���X�g�m���@ */
	case WZ_HEAVENDRIVE:		/* �w�����Y�h���C�u */
		limit=500;
		range=2;
		break;

	case WZ_METEOR:				/* ���e�I�X�g�[�� */
		limit=500;
		range=3;
		break;

	case WZ_SIGHTRASHER:
		limit=500;
		count=41;
		break;

	case WZ_VERMILION:			/* ���[�h�I�u���@�[�~���I�� */
		limit=4100;
		interval=1000;
		range=6;
		break;

	case WZ_ICEWALL:			/* �A�C�X�E�H�[�� */
		limit=skill_get_time(skillid,skilllv);
		count=5;
		break;

	case WZ_STORMGUST:			/* �X�g�[���K�X�g */
		limit=4600;
		interval=450;
		range=5;
		break;

	case WZ_QUAGMIRE:			/* �N�@�O�}�C�A */
		limit=skill_get_time(skillid,skilllv);
		interval=200;
		count=25;
		break;

	case HT_SKIDTRAP:			/* �X�L�b�h�g���b�v */
		limit=skill_get_time(skillid,skilllv);
		range=1;
		break;

	case HT_LANDMINE:			/* �����h�}�C�� */
		limit=skill_get_time(skillid,skilllv);
		range=1;
		break;

	case HT_ANKLESNARE:			/* �A���N���X�l�A */
		limit=skill_get_time(skillid,skilllv);
		range=1;
		break;

	case HT_SHOCKWAVE:			/* �V���b�N�E�F�[�u�g���b�v */
		limit=skill_get_time(skillid,skilllv);
		range=1;
		val1=skilllv*15+10;
		break;

	case HT_SANDMAN:			/* �T���h�}�� */
		limit=skill_get_time(skillid,skilllv);
		range=1;
		break;

	case HT_FLASHER:			/* �t���b�V���[ */
		limit=skill_get_time(skillid,skilllv);
		range=1;
		break;

	case HT_FREEZINGTRAP:		/* �t���[�W���O�g���b�v */
		limit=skill_get_time(skillid,skilllv);
		range=1;
		break;

	case HT_BLASTMINE:			/* �u���X�g�}�C�� */
		limit=skill_get_time(skillid,skilllv);
		range=1;
		break;

	case HT_CLAYMORETRAP:		/* �N���C���A�[�g���b�v */
		limit=skill_get_time(skillid,skilllv);
		range=1;
		break;

	case AS_VENOMDUST:			/* �x�m���_�X�g */
		limit=skill_get_time(skillid,skilllv);
		interval=1000;
		count=5;
		break;

	case CR_GRANDCROSS:			/* �O�����h�N���X */
		count=29;
		limit=1000;
		interval=300;
		break;

	case SA_VOLCANO:			/* �{���P�[�m */
	case SA_DELUGE:				/* �f�����[�W */
	case SA_VIOLENTGALE:				/* �o�C�I�����g�Q�C�� */
		limit=skill_get_time(skillid,skilllv);
		count=skilllv<=2?25:(skilllv<=4?49:81);
		target=BCT_ALL;
		break;
	case SA_LANDPROTECTOR:				/* �����h�v���e�N�^�[ */
		limit=skill_get_time(skillid,skilllv);
		count=skilllv<=2?49:(skilllv<=4?81:121);
		target=BCT_ALL;
		break;

	case BD_LULLABY:			/* �q��S */
	case BD_ETERNALCHAOS:		/* �G�^�[�i���J�I�X */
	case BD_ROKISWEIL:			/* ���L�̋��� */
		count=81;
		limit=skill_get_time(skillid,skilllv);
		range=5;
		target=BCT_ALL;
		break;
	case BD_RICHMANKIM:
	case BD_DRUMBATTLEFIELD:	/* �푾�ۂ̋��� */
	case BD_RINGNIBELUNGEN:		/* �j�[�x�����O�̎w�� */
	case BD_INTOABYSS:			/* �[���̒��� */
	case BD_SIEGFRIED:			/* �s���g�̃W�[�N�t���[�h */
		count=81;
		limit=skill_get_time(skillid,skilllv);
		range=5;
		target=BCT_PARTY;
		break;

	case BA_WHISTLE:			/* ���J */
		count=81;
		limit=skill_get_time(skillid,skilllv);
		range=5;
		target=BCT_NOENEMY;
		if(src->type == BL_PC)
			val1 = (pc_checkskill((struct map_session_data *)src,BA_MUSICALLESSON)+1)>>1;
		val2 = ((battle_get_agi(src)/10)&0xffff)<<16;
		val2 |= (battle_get_luk(src)/10)&0xffff;
		break;
	case DC_HUMMING:			/* �n�~���O */
		count=81;
		limit=skill_get_time(skillid,skilllv);
		range=5;
		target=BCT_NOENEMY;
		if(src->type == BL_PC)
			val1 = (pc_checkskill((struct map_session_data *)src,DC_DANCINGLESSON)+1)>>1;
		val2 = battle_get_dex(src)/10;
		break;

	case BA_DISSONANCE:			/* �s���a�� */
	case DC_UGLYDANCE:			/* ��������ȃ_���X */
		count=81;
		limit=skill_get_time(skillid,skilllv);
		range=5;
		target=BCT_ENEMY;
		break;

	case DC_DONTFORGETME:		/* ����Y��Ȃ��Łc */
		count=81;
		limit=skill_get_time(skillid,skilllv);
		range=5;
		target=BCT_ENEMY;
		if(src->type == BL_PC)
			val1 = (pc_checkskill((struct map_session_data *)src,DC_DANCINGLESSON)+1)>>1;
		val2 = ((battle_get_str(src)/20)&0xffff)<<16;
		val2 |= (battle_get_agi(src)/10)&0xffff;
		break;
	case BA_POEMBRAGI:			/* �u���M�̎� */
		count=81;
		limit=skill_get_time(skillid,skilllv);
		range=5;
		target=BCT_NOENEMY;
		if(src->type == BL_PC)
			val1 = pc_checkskill((struct map_session_data *)src,BA_MUSICALLESSON);
		val2 = ((battle_get_dex(src)/10)&0xffff)<<16;
		val2 |= (battle_get_int(src)/5)&0xffff;
		break;
	case BA_APPLEIDUN:			/* �C�h�D���̗ь� */
		count=81;
		limit=skill_get_time(skillid,skilllv);
		range=5;
		target=BCT_NOENEMY;
		if(src->type == BL_PC)
			val1 = ((pc_checkskill((struct map_session_data *)src,BA_MUSICALLESSON))&0xffff)<<16;
		else
			val1 = 0;
		val1 |= (battle_get_vit(src))&0xffff;
		val2 = 0;//�񕜗p�^�C���J�E���^(6�b����1����)
		break;
	case DC_SERVICEFORYOU:		/* �T�[�r�X�t�H�[���[ */
		count=81;
		limit=skill_get_time(skillid,skilllv);
		range=5;
		target=BCT_PARTY;
		if(src->type == BL_PC)
			val1 = (pc_checkskill((struct map_session_data *)src,DC_DANCINGLESSON)+1)>>1;
		val2 = battle_get_int(src)/10;
		break;
	case BA_ASSASSINCROSS:		/* �[�z�̃A�T�V���N���X */
		count=81;
		limit=skill_get_time(skillid,skilllv);
		range=5;
		target=BCT_NOENEMY;
		if(src->type == BL_PC)
			val1 = (pc_checkskill((struct map_session_data *)src,BA_MUSICALLESSON)+1)>>1;
		val2 = battle_get_agi(src)/20;
		break;
	case DC_FORTUNEKISS:		/* �K�^�̃L�X */
		count=81;
		limit=skill_get_time(skillid,skilllv);
		range=5;
		target=BCT_NOENEMY;
		if(src->type == BL_PC)
			val1 = (pc_checkskill((struct map_session_data *)src,DC_DANCINGLESSON)+1)>>1;
		val2 = battle_get_luk(src)/10;
		break;
	case AM_DEMONSTRATION:		/* �f�����X�g���[�V���� */
		count=9;
		limit=skill_get_time(skillid,skilllv);
		interval=1000;
		range=1;
		target=BCT_ENEMY;
		break;
	};

	group=skill_initunitgroup(src,count,skillid,skilllv,
		skill_get_unit_id(skillid,flag&1));
	group->limit=limit;
	group->val1=val1;
	group->val2=val2;
	group->target_flag=target;
	group->interval=interval;
	group->range=range;

	for(i=0;i<count;i++){
		struct skill_unit *unit;
		int ux=x,uy=y,val1=skilllv,val2=0,limit=group->limit,alive=1;
		int range=group->range;
		switch(skillid){	/* �ݒ� */
		case AL_PNEUMA:				/* �j���[�} */
			{
				static const int dx[9]={-1, 0, 1,-1, 0, 1,-1, 0, 1};
				static const int dy[9]={-1,-1,-1, 0, 0, 0, 1, 1, 1};
				ux+=dx[i];
				uy+=dy[i];
			}
			break;
		case MG_FIREWALL:		/* �t�@�C���[�E�H�[�� */
			{
				if(dir&1){	/* �΂ߔz�u */
					static const int dx[][5]={
						{ 1,1,0,0,-1 }, { -1,-1,0,0,1 },
					},dy[][5]={
						{ 1,0,0,-1,-1 }, { 1,0,0,-1,-1 },
					};
					ux+=dx[(dir>>1)&1][i];
					uy+=dy[(dir>>1)&1][i];
				}else{	/* �㉺�z�u */
					if(dir%4==0)	/* �㉺ */
						ux+=i-1;
					else			/* ���E */
						uy+=i-1;
				}
				val2=group->val2;
			}
			break;

		case PR_SANCTUARY:		/* �T���N�`���A�� */
			{
				static const int dx[]={
					-1,0,1, -2,-1,0,1,2, -2,-1,0,1,2, -2,-1,0,1,2, -1,0,1 };
				static const int dy[]={
					-2,-2,-2, -1,-1,-1,-1,-1, 0,0,0,0,0, 1,1,1,1,1, 2,2,2, };
				ux+=dx[i];
				uy+=dy[i];
			}
			break;

		case PR_MAGNUS:			/* �}�O�k�X�G�N�\�V�Y�� */
			{
				static const int dx[]={ -1,0,1, -1,0,1, -3,-2,-1,0,1,2,3,
					-3,-2,-1,0,1,2,3, -3,-2,-1,0,1,2,3, -1,0,1, -1,0,1, };
				static const int dy[]={
					-3,-3,-3, -2,-2,-2, -1,-1,-1,-1,-1,-1,-1,
					0,0,0,0,0,0,0, 1,1,1,1,1,1,1, 2,2,2, 3,3,3 };
				ux+=dx[i];
				uy+=dy[i];
			}
			break;

		case WZ_SIGHTRASHER:
			{
				static const int dx[]={
					-5, 0, 5, -4, 0, 4, -3, 0, 3, -2, 0, 2, -1, 0, 1, -5,-4,-3,-2,-1, 0, 1, 2, 3, 4, 5, -1, 0, 1, -2, 0, 2, -3, 0, 3, -4, 0, 4, -5, 0, 5 };
				static const int dy[]={
					-5,-5,-5, -4,-4,-4, -3,-3,-3, -2,-2,-2, -1,-1,-1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  1, 1, 1,  2, 2, 2,  3, 3, 3,  4, 4, 4,  5, 5, 5 };
				ux+=dx[i];
				uy+=dy[i];
			}
			break;

		case WZ_ICEWALL:		/* �A�C�X�E�H�[�� */
			{
				static const int dirx[8]={0,-1,-1,-1,0,1,1,1};
				static const int diry[8]={1,1,0,-1,-1,-1,0,1};
				if(skilllv <= 1)
					val1 = 500;
				else
					val1 = 200 + 200*skilllv;
				if(src->x == x && src->y == y)
					dir = 2;
				else
					dir=map_calc_dir(src,x,y);
				ux+=(2-i)*diry[dir];
				uy+=(i-2)*dirx[dir];
			}
			break;

		case WZ_QUAGMIRE:		/* �N�@�O�}�C�A */
			ux+=(i%5-2);
			uy+=(i/5-2);
			if(i==12)
				range=2;
			else
				range=-1;

			break;

		case AS_VENOMDUST:		/* �x�m���_�X�g */
			{
				static const int dx[]={-1,0,0,0,1};
				static const int dy[]={0,-1,0,1,0};
				ux+=dx[i];
				uy+=dy[i];
			}
			break;

		case CR_GRANDCROSS:		/* �O�����h�N���X */
			{
				static const int dx[]={
					0, 0, -1,0,1, -2,-1,0,1,2, -4,-3,-2,-1,0,1,2,3,4, -2,-1,0,1,2, -1,0,1, 0, 0, };
				static const int dy[]={
					-4, -3, -2,-2,-2, -1,-1,-1,-1,-1, 0,0,0,0,0,0,0,0,0, 1,1,1,1,1, 2,2,2, 3, 4, };
				ux+=dx[i];
				uy+=dy[i];
			}
			break;
		case SA_VOLCANO:			/* �{���P�[�m */
		case SA_DELUGE:				/* �f�����[�W */
		case SA_VIOLENTGALE:				/* �o�C�I�����g�Q�C�� */
			{
				int u_range=0,central=0;
				if(skilllv<=2){
					u_range=2;
					central=12;
				}else if(skilllv<=4){
					u_range=3;
					central=24;
				}else if(skilllv>=5){
					u_range=4;
					central=40;
				}
				ux+=(i%(u_range*2+1)-u_range);
				uy+=(i/(u_range*2+1)-u_range);

				if(i==central)
					range=u_range;//�����̃��j�b�g�̌��ʔ͈͂͑S�͈�
				else
					range=-1;//�����ȊO�̃��j�b�g�͏���
			}
			break;
		case SA_LANDPROTECTOR:				/* �����h�v���e�N�^�[ */
			{
				int u_range=0;

				if(skilllv<=2) u_range=3;
				else if(skilllv<=4) u_range=4;
				else if(skilllv>=5) u_range=5;

				ux+=(i%(u_range*2+1)-u_range);
				uy+=(i/(u_range*2+1)-u_range);

				range=0;
			}
			break;

		case AM_DEMONSTRATION:		/* �f�����X�g���[�V���� */
			ux+=(i%3-2);
			uy+=(i/3-2);
			if(i==4)
				range=1;
			else
				range=-1;

			break;

		/* �_���X�Ȃ� */
		case BD_LULLABY:		/* �q��� */
		case BD_RICHMANKIM:		/* �j�����h�̉� */
		case BD_ETERNALCHAOS:	/* �i���̍��� */
		case BD_DRUMBATTLEFIELD:/* �푾�ۂ̋��� */
		case BD_RINGNIBELUNGEN:	/* �j�[�x�����O�̎w�� */
		case BD_ROKISWEIL:		/* ���L�̋��� */
		case BD_INTOABYSS:		/* �[���̒��� */
		case BD_SIEGFRIED:		/* �s���g�̃W�[�N�t���[�h */
		case BA_DISSONANCE:		/* �s���a�� */
		case BA_WHISTLE:		/* ���J */
		case BA_ASSASSINCROSS:	/* �[�z�̃A�T�V���N���X */
		case BA_POEMBRAGI:		/* �u���M�̎� */
		case BA_APPLEIDUN:		/* �C�h�D���̗ь� */
		case DC_UGLYDANCE:		/* ��������ȃ_���X */
		case DC_HUMMING:		/* �n�~���O */
		case DC_DONTFORGETME:	/* ����Y��Ȃ��Łc */
		case DC_FORTUNEKISS:	/* �K�^�̃L�X */
		case DC_SERVICEFORYOU:	/* �T�[�r�X�t�H�[���[ */
			ux+=(i%9-4);
			uy+=(i/9-4);
			if(i==40)
				range=4;	/* ���S�̏ꍇ�͔͈͂�4�ɃI�[�o�[���C�h */
			else
				range=-1;	/* ���S����Ȃ��ꍇ�͔͈͂�-1�ɃI�[�o�[���C�h */
			break;
		}
		//����X�L���̏ꍇ�ݒu���W��Ƀ����h�v���e�N�^�[���Ȃ����`�F�b�N
		if(range<=0)
			map_foreachinarea(skill_landprotector,src->m,ux,uy,ux,uy,BL_SKILL,skillid,&alive);

		if(skillid==WZ_ICEWALL && alive){
			val2=map_getcell(src->m,ux,uy);
			if(val2==5 || val2==1)
				alive=0;
			else {
				map_setcell(src->m,ux,uy,5);
				clif_changemapcell(src->m,ux,uy,5,0);
			}
		}

		if(alive){
			unit=skill_initunit(group,i,ux,uy);
			unit->val1=val1;
			unit->val2=val2;
			unit->limit=limit;
			unit->range=range;
		}
	}
	return group;
}

/*==========================================
 * �X�L�����j�b�g�̔����C�x���g
 *------------------------------------------
 */
int skill_unit_onplace(struct skill_unit *src,struct block_list *bl,unsigned int tick)
{
	struct skill_unit_group *sg= src->group;
	struct block_list *ss=map_id2bl(sg->src_id);
	struct skill_unit_group_tickset *ts;
	int diff,goflag;

	if(bl == NULL ||  bl->prev==NULL || !src->alive || (bl->type == BL_PC && pc_isdead((struct map_session_data *)bl) ) )
		return 0;
	if( bl->type!=BL_PC && bl->type!=BL_MOB)
		return 0;

	if(ss==NULL)
		return 0;

	ts=skill_unitgrouptickset_search( bl, sg->group_id);
	diff=DIFF_TICK(tick,ts->tick);
	goflag=(diff>sg->interval || diff<0);

	//�Ώۂ�LP��ɋ���ꍇ�͖���
	map_foreachinarea(skill_landprotector,bl->m,bl->x,bl->y,bl->x,bl->y,BL_SKILL,0,&goflag);

	if(!goflag)
		return 0;
	ts->tick=tick;
	ts->group_id=sg->group_id;

	switch(sg->unit_id){
	case 0x83:	/* �T���N�`���A�� */
		{
			int race=battle_get_race(bl);
			int damage_flag = (battle_check_undead(race,battle_get_elem_type(bl)) || race == 6)? 1:0;

			if( battle_get_hp(bl)>=battle_get_max_hp(bl) && !damage_flag)
				break;

			if((sg->val1--)<=0){
				skill_delunitgroup(sg);
				return 0;
			}
			if(!damage_flag) {
				int heal=sg->val2;
				if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage)
					heal=0;	/* ����峃J�[�h�i�q�[���ʂO�j */
				clif_skill_nodamage(&src->bl,bl,AL_HEAL,heal,1);
				battle_heal(NULL,bl,heal,0,0);
			}
			else
				skill_attack(BF_MAGIC,ss,&src->bl,bl,sg->skill_id,sg->skill_lv,tick,0);
		}
		break;

	case 0x84:	/* �}�O�k�X�G�N�\�V�Y�� */
		{
			int race=battle_get_race(bl);
			int damage_flag = (battle_check_undead(race,battle_get_elem_type(bl)) || race == 6)? 1:0;

			if(!damage_flag)
				return 0;
			skill_attack(BF_MAGIC,ss,&src->bl,bl,sg->skill_id,sg->skill_lv,tick,0);
		}
		break;

	case 0x85:	/* �j���[�} */
		{
			struct skill_unit *unit2;
			struct status_change *sc_data=battle_get_sc_data(bl);
			int type=SC_PNEUMA;
			if(sc_data[type].timer==-1)
				skill_status_change_start(bl,type,src->group->skill_lv,(int)src,0,0,0,0);
			else if((unit2=(struct skill_unit *)sc_data[type].val2)!=src){
				if(DIFF_TICK(sg->tick,unit2->group->tick)>0 )
					skill_status_change_start(bl,type,src->group->skill_lv,(int)src,0,0,0,0);
				ts->tick-=sg->interval;
			}
		}
		break;
	case 0x7e:	/* �Z�C�t�e�B�E�H�[�� */
		{
			struct skill_unit *unit2;
			struct status_change *sc_data=battle_get_sc_data(bl);
			int type=SC_SAFETYWALL;
			if(sc_data[type].timer==-1)
				skill_status_change_start(bl,type,src->group->skill_lv,(int)src,0,0,0,0);
			else if((unit2=(struct skill_unit *)sc_data[type].val2)!=src){
				if(sg->val1 < unit2->group->val1 )
					skill_status_change_start(bl,type,src->group->skill_lv,(int)src,0,0,0,0);
				ts->tick-=sg->interval;
			}
		}
		break;

	case 0x86:	/* ���[�h�I�u���@�[�~���I��(���X�g�[���K�X�g ���O�����h�N���X) */
		skill_attack(BF_MAGIC,ss,&src->bl,bl,sg->skill_id,sg->skill_lv,tick,0);
		break;

	case 0x7f:	/* �t�@�C���[�E�H�[�� */
		if( (src->val2--)>0)
			skill_attack(BF_MAGIC,ss,&src->bl,bl,
				sg->skill_id,sg->skill_lv,tick,0);
		if( src->val2<=0 )
			skill_delunit(src);
		break;

	case 0x87:	/* �t�@�C�A�[�s���[(�����O) */
		skill_delunit(src);
		skill_unitsetting(ss,sg->skill_id,sg->skill_lv,src->bl.x,src->bl.y,1);
		break;

	case 0x88:	/* �t�@�C�A�[�s���[(������) */
		if(DIFF_TICK(tick,sg->tick) < 150)
			skill_attack(BF_MAGIC,ss,&src->bl,bl,sg->skill_id,sg->skill_lv,tick,0);
		break;

	case 0x90:	/* �X�L�b�h�g���b�v */
		{
			int i,c = skill_get_blewcount(sg->skill_id,sg->skill_lv);
			if(map[bl->m].flag.gvg) c = 0;
			for(i=0;i<c;i++)
				skill_blown(&src->bl,bl,1|0x30000);
			sg->unit_id = 0x8c;
			clif_changelook(&src->bl,LOOK_BASE,sg->unit_id);
			sg->limit=DIFF_TICK(tick,sg->tick)+1500;
		}
		break;

	case 0x93:	/* �����h�}�C�� */
		skill_attack(BF_MISC,ss,&src->bl,bl,sg->skill_id,sg->skill_lv,tick,0);
		sg->unit_id = 0x8c;
		clif_changelook(&src->bl,LOOK_BASE,0x88);
		sg->limit=DIFF_TICK(tick,sg->tick)+1500;
		break;

	case 0x8f:	/* �u���X�g�}�C�� */
	case 0x97:	/* �t���[�W���O�g���b�v */
	case 0x98:	/* �N���C���A�[�g���b�v */
		skill_attack((sg->unit_id==0x97)?BF_WEAPON:BF_MISC,
			ss,&src->bl,bl,sg->skill_id,sg->skill_lv,tick,(sg->val2)?0x0500:0);
		sg->unit_id = 0x8c;
		clif_changelook(&src->bl,LOOK_BASE,sg->unit_id);
		sg->limit=DIFF_TICK(tick,sg->tick)+1500;
		break;

	case 0x95:	/* �T���h�}�� */
	case 0x96:	/* �t���b�V���[ */
	case 0x94:	/* �V���b�N�E�F�[�u�g���b�v */
		skill_additional_effect(ss,bl,sg->skill_id,sg->skill_lv,BF_MISC,tick);
		sg->unit_id = 0x8c;
		clif_changelook(&src->bl,LOOK_BASE,sg->unit_id);
		sg->limit=DIFF_TICK(tick,sg->tick)+1500;
		break;

	case 0x91:	/* �A���N���X�l�A */
		if(sg->val2==0){
			skill_additional_effect(ss,bl,sg->skill_id,sg->skill_lv,BF_MISC,tick);
			bl->x = (&src->bl)->x;
			bl->y = (&src->bl)->y;
 			if(bl->type == BL_MOB)
 				clif_fixmobpos((struct mob_data *)bl);
 			else if(bl->type == BL_PET)
 				clif_fixpetpos((struct pet_data *)bl);
 			else
 				clif_fixpos(bl);
			clif_01ac(&src->bl);
			sg->limit=DIFF_TICK(tick,sg->tick) + skill_get_time2(sg->skill_id,sg->skill_lv);
			sg->val2=bl->id;
		}
		break;

	case 0x80:	/* ���[�v�|�[�^��(������) */
		if(bl->type==BL_PC){
			struct map_session_data *sd = (struct map_session_data *)bl;
			if(src->bl.m == bl->m && src->bl.x == bl->x && src->bl.y == bl->y && src->bl.x == sd->to_x && src->bl.y == sd->to_y) {
				if( battle_config.chat_warpportal || !sd->chatID ){
					if((sg->val1--)>0){
						pc_setpos(sd,sg->valstr,sg->val2>>16,sg->val2&0xffff,3);
					}else
						skill_delunitgroup(sg);
				}
			}
		}else if(bl->type==BL_MOB && battle_config.mob_warpportal){
			int m=map_mapname2mapid(sg->valstr);
			mob_warp((struct mob_data *)bl,m,sg->val2>>16,sg->val2&0xffff,3);
		}
		break;

	case 0x8e:	/* �N�@�O�}�C�A */
		{
			int type=SkillStatusChangeTable[sg->skill_id];
			if( bl->type==BL_PC && ((struct map_session_data *)bl)->special_state.no_magic_damage )
				break;
			if( battle_get_sc_data(bl)[type].timer==-1 )
				skill_status_change_start(bl,type,src->group->skill_lv,(int)src,0,0,skill_get_time2(src->group->skill_id,src->group->skill_lv),0);
		}
		break;
	case 0x92:	/* �x�m���_�X�g */
		{
			int type=SkillStatusChangeTable[sg->skill_id];
			if( battle_get_sc_data(bl)[type].timer==-1 )
				skill_status_change_start(bl,type,src->group->skill_lv,(int)src,0,0,skill_get_time2(src->group->skill_id,src->group->skill_lv),0);
		}
		break;
	case 0x9a:	/* �{���P�[�m */
	case 0x9b:	/* �f�����[�W */
	case 0x9c:	/* �o�C�I�����g�Q�C�� */
		{
			struct skill_unit *unit2;
			struct status_change *sc_data=battle_get_sc_data(bl);
			int type=SkillStatusChangeTable[sg->skill_id];
			if(sc_data[type].timer==-1)
				skill_status_change_start(bl,type,src->group->skill_lv,(int)src,0,0,skill_get_time2(src->group->skill_id,src->group->skill_lv),0);
			else if((unit2=(struct skill_unit *)sc_data[type].val2)!=src){
				if( DIFF_TICK(sg->tick,unit2->group->tick)>0 )
					skill_status_change_start(bl,type,src->group->skill_lv,(int)src,0,0,skill_get_time2(src->group->skill_id,src->group->skill_lv),0);
				ts->tick-=sg->interval;
			}
		} break;

	case 0x9e:	/* �q��S */
	case 0x9f:	/* �j�����h�̉� */
	case 0xa0:	/* �i���̍��� */
	case 0xa1:	/* �푾�ۂ̋��� */
	case 0xa2:	/* �j�[�x�����O�̎w�� */
	case 0xa3:	/* ���L�̋��� */
	case 0xa4:	/* �[���̒��� */
	case 0xa5:	/* �s���g�̃W�[�N�t���[�h */
	case 0xa6:	/* �s���a�� */
	case 0xa7:	/* ���J */
	case 0xa8:	/* �[�z�̃A�T�V���N���X */
	case 0xa9:	/* �u���M�̎� */
	case 0xab:	/* ��������ȃ_���X */
	case 0xac:	/* �n�~���O */
	case 0xad:	/* ����Y��Ȃ��Łc */
	case 0xae:	/* �K�^�̃L�X */
	case 0xaf:	/* �T�[�r�X�t�H�[���[ */
		{
			struct skill_unit *unit2;
			struct status_change *sc_data=battle_get_sc_data(bl);
			int type=SkillStatusChangeTable[sg->skill_id];
			if(sg->src_id == bl->id)
				break;
			if(sc_data[type].timer==-1)
				skill_status_change_start(bl,type,src->group->skill_lv,src->group->val1,src->group->val2,
					(int)src,skill_get_time2(src->group->skill_id,src->group->skill_lv),0);
			else if((unit2=(struct skill_unit *)sc_data[type].val4)!=src){
				if( DIFF_TICK(sg->tick,unit2->group->tick)>0 )
					skill_status_change_start(bl,type,src->group->skill_lv,src->group->val1,src->group->val2,
						(int)src,skill_get_time2(src->group->skill_id,src->group->skill_lv),0);
				ts->tick-=sg->interval;
			}
		} break;

	case 0xaa:	/* �C�h�D���̗ь� */
		{
			struct skill_unit *unit2;
			struct status_change *sc_data=battle_get_sc_data(bl);
			int type=SkillStatusChangeTable[sg->skill_id];
			if(sg->src_id == bl->id)
				break;
			if(sc_data[type].timer==-1)
				skill_status_change_start(bl,type,src->group->skill_lv,(src->group->val1)>>16,(src->group->val1)&0xffff,
					(int)src,skill_get_time2(src->group->skill_id,src->group->skill_lv),0);
			else if((unit2=(struct skill_unit *)sc_data[type].val4)!=src){
				if( DIFF_TICK(sg->tick,unit2->group->tick)>0 )
					skill_status_change_start(bl,type,src->group->skill_lv,(src->group->val1)>>16,(src->group->val1)&0xffff,
						(int)src,skill_get_time2(src->group->skill_id,src->group->skill_lv),0);
				ts->tick-=sg->interval;
			}
		} break;

	case 0xb1:	/* �f�����X�g���[�V���� */
		skill_attack(BF_WEAPON,ss,&src->bl,bl,sg->skill_id,sg->skill_lv,tick,0);
//		if(bl->type == BL_PC && rand()%100 < sg->skill_lv)
//			pc_break_weapon((struct map_session_data *)bl);
		break;
/*	default:
		if(battle_config.error_log)
			printf("skill_unit_onplace: Unknown skill unit id=%d block=%d\n",sg->unit_id,bl->id);
		break;*/
	}
	if(bl->type==BL_MOB && ss!=bl)	/* �X�L���g�p������MOB�X�L�� */
	{
		if(battle_config.mob_changetarget_byskill == 1)
		{
			int target=((struct mob_data *)bl)->target_id;
			if(ss->type == BL_PC)
				((struct mob_data *)bl)->target_id=ss->id;
			mobskill_use((struct mob_data *)bl,tick,MSC_SKILLUSED|(sg->skill_id<<16));
			((struct mob_data *)bl)->target_id=target;
		}
		else
			mobskill_use((struct mob_data *)bl,tick,MSC_SKILLUSED|(sg->skill_id<<16));
	}

	return 0;
}
/*==========================================
 * �X�L�����j�b�g���痣�E����(�������͂��Ă���)�ꍇ
 *------------------------------------------
 */
int skill_unit_onout(struct skill_unit *src,struct block_list *bl,unsigned int tick)
{
	struct skill_unit_group *sg= src->group;

	if(bl == NULL || bl->prev==NULL || !src->alive)
		return 0;
	if( bl->type!=BL_PC && bl->type!=BL_MOB )
		return 0;

	switch(sg->unit_id){
	case 0x7e:	/* �Z�C�t�e�B�E�H�[�� */
	case 0x85:	/* �j���[�} */
	case 0x8e:	/* �N�@�O�}�C�A */
		{
			struct skill_unit *unit2;
			struct status_change *sc_data=battle_get_sc_data(bl);
			int type=
				(sg->unit_id==0x85)?SC_PNEUMA:
				((sg->unit_id==0x7e)?SC_SAFETYWALL:
				 SC_QUAGMIRE);
			if((type != SC_QUAGMIRE || bl->type != BL_MOB) &&
				sc_data[type].timer!=-1 && (unit2=(struct skill_unit *)sc_data[type].val2)==src){
				skill_status_change_end(bl,type,-1);
			}
		} break;

	case 0x91:	/* �A���N���X�l�A */
		{
			struct block_list *target=map_id2bl(sg->val2);
			if( target==bl )
				skill_status_change_end(bl,SC_ANKLE,-1);
			sg->limit=DIFF_TICK(tick,sg->tick)+1000;
		}
		break;
	case 0x9a:	/* �{���P�[�m */
	case 0x9b:	/* �f�����[�W */
	case 0x9c:	/* �o�C�I�����g�Q�C�� */
		{
			struct skill_unit *unit2;
			struct status_change *sc_data=battle_get_sc_data(bl);
			int type=SkillStatusChangeTable[sg->skill_id];
			if(sc_data[type].timer!=-1 && (unit2=(struct skill_unit *)sc_data[type].val2)==src){
				skill_status_change_end(bl,type,-1);
			}
		}
		break;

	case 0x9e:	/* �q��S */
	case 0x9f:	/* �j�����h�̉� */
	case 0xa0:	/* �i���̍��� */
	case 0xa1:	/* �푾�ۂ̋��� */
	case 0xa2:	/* �j�[�x�����O�̎w�� */
	case 0xa3:	/* ���L�̋��� */
	case 0xa4:	/* �[���̒��� */
	case 0xa5:	/* �s���g�̃W�[�N�t���[�h */
	case 0xa6:	/* �s���a�� */
	case 0xa7:	/* ���J */
	case 0xa8:	/* �[�z�̃A�T�V���N���X */
	case 0xa9:	/* �u���M�̎� */
	case 0xaa:	/* �C�h�D���̗ь� */
	case 0xab:	/* ��������ȃ_���X */
	case 0xac:	/* �n�~���O */
	case 0xad:	/* ����Y��Ȃ��Łc */
	case 0xae:	/* �K�^�̃L�X */
	case 0xaf:	/* �T�[�r�X�t�H�[���[ */
		{
			struct skill_unit *unit2;
			struct status_change *sc_data=battle_get_sc_data(bl);
			int type=SkillStatusChangeTable[sg->skill_id];
			if(sc_data[type].timer!=-1 && (unit2=(struct skill_unit *)sc_data[type].val4)==src){
				skill_status_change_end(bl,type,-1);
			}
		}
		break;

/*	default:
		if(battle_config.error_log)
			printf("skill_unit_onout: Unknown skill unit id=%d block=%d\n",sg->unit_id,bl->id);
		break;*/
	}
	skill_unitgrouptickset_delete(bl,sg->group_id);
	return 0;
}
/*==========================================
 * �X�L�����j�b�g�̍폜�C�x���g
 *------------------------------------------
 */
int skill_unit_ondelete(struct skill_unit *src,struct block_list *bl,unsigned int tick)
{
	struct skill_unit_group *sg= src->group;

	if(bl == NULL || bl->prev==NULL || !src->alive)
		return 0;
	if( bl->type!=BL_PC && bl->type!=BL_MOB )
		return 0;

	switch(sg->unit_id){
	case 0x85:	/* �j���[�} */
	case 0x7e:	/* �Z�C�t�e�B�E�H�[�� */
	case 0x8e:	/* �N�@�O�}�C�� */
	case 0x9a:	/* �{���P�[�m */
	case 0x9b:	/* �f�����[�W */
	case 0x9c:	/* �o�C�I�����g�Q�C�� */
	case 0x9e:	/* �q��S */
	case 0x9f:	/* �j�����h�̉� */
	case 0xa0:	/* �i���̍��� */
	case 0xa1:	/* �푾�ۂ̋��� */
	case 0xa2:	/* �j�[�x�����O�̎w�� */
	case 0xa3:	/* ���L�̋��� */
	case 0xa4:	/* �[���̒��� */
	case 0xa5:	/* �s���g�̃W�[�N�t���[�h */
	case 0xa6:	/* �s���a�� */
	case 0xa7:	/* ���J */
	case 0xa8:	/* �[�z�̃A�T�V���N���X */
	case 0xa9:	/* �u���M�̎� */
	case 0xaa:	/* �C�h�D���̗ь� */
	case 0xab:	/* ��������ȃ_���X */
	case 0xac:	/* �n�~���O */
	case 0xad:	/* ����Y��Ȃ��Łc */
	case 0xae:	/* �K�^�̃L�X */
	case 0xaf:	/* �T�[�r�X�t�H�[���[ */
		return skill_unit_onout(src,bl,tick);

/*	default:
		if(battle_config.error_log)
			printf("skill_unit_ondelete: Unknown skill unit id=%d block=%d\n",sg->unit_id,bl->id);
		break;*/
	}
	skill_unitgrouptickset_delete(bl,sg->group_id);
	return 0;
}
/*==========================================
 * �X�L�����j�b�g�̌��E�C�x���g
 *------------------------------------------
 */
int skill_unit_onlimit(struct skill_unit *src,unsigned int tick)
{
	struct skill_unit_group *sg= src->group;

	switch(sg->unit_id){
	case 0x81:	/* ���[�v�|�[�^��(�����O) */
		{
			struct skill_unit_group *group=
				skill_unitsetting(map_id2bl(sg->src_id),sg->skill_id,sg->skill_lv,
					src->bl.x,src->bl.y,1);
			group->valstr=calloc(24, 1);
			if(group->valstr==NULL){
				printf("skill_unit_ondelete: out of memory !\n");
				exit(1);
			}
			memcpy(group->valstr,sg->valstr,24);
			group->val2=sg->val2;
		}
		break;

	case 0x8d:	/* �A�C�X�E�H�[�� */
		map_setcell(src->bl.m,src->bl.x,src->bl.y,src->val2);
		clif_changemapcell(src->bl.m,src->bl.x,src->bl.y,src->val2,1);
		break;

	}
	return 0;
}
/*==========================================
 * �X�L�����j�b�g�̃_���[�W�C�x���g
 *------------------------------------------
 */
int skill_unit_ondamaged(struct skill_unit *src,struct block_list *bl,
	int damage,unsigned int tick)
{
	struct skill_unit_group *sg= src->group;

	switch(sg->unit_id){
	case 0x8d:	/* �A�C�X�E�H�[�� */
		src->val1-=damage;
		break;
	default:
		damage = 0;
		break;
	}
	return damage;
}


/*---------------------------------------------------------------------------- */



/*==========================================
 * �X�L���g�p�i�r�������A�ꏊ�w��j
 *------------------------------------------
 */
int skill_castend_pos( int tid, unsigned int tick, int id,int data )
{
	struct map_session_data* sd=NULL/*,*target_sd=NULL*/;
	int range,maxcount;

	if( (sd=map_id2sd(id))==NULL || sd->bl.prev == NULL)
		return 0;

	if( sd->skilltimer != tid )	/* �^�C�}ID�̊m�F */
		return 0;
	if(sd->skilltimer != -1 && pc_checkskill(sd,SA_FREECAST) > 0) {
		sd->speed = sd->prev_speed;
		clif_updatestatus(sd,SP_SPEED);
	}
	sd->skilltimer=-1;
	if(pc_isdead(sd)) {
		sd->canact_tick = tick;
		sd->canmove_tick = tick;
		sd->skillitem = sd->skillitemlv = -1;
		return 0;
	}

	if(battle_config.pc_skill_reiteration == 0) {
		range = -1;
		switch(sd->skillid) {
			case MG_SAFETYWALL:
			case WZ_FIREPILLAR:
			case HT_SKIDTRAP:
			case HT_LANDMINE:
			case HT_ANKLESNARE:
			case HT_SHOCKWAVE:
			case HT_SANDMAN:
			case HT_FLASHER:
			case HT_FREEZINGTRAP:
			case HT_BLASTMINE:
			case HT_CLAYMORETRAP:
			case HT_TALKIEBOX:
			case AL_WARP:
				range = 0;
				break;
			case AL_PNEUMA:
				range = 1;
				break;
		}
		if(range >= 0) {
			if(skill_check_unit_range(sd->bl.m,sd->skillx,sd->skilly,range,sd->skillid) > 0) {
				clif_skill_fail(sd,sd->skillid,0,0);
				sd->canact_tick = tick;
				sd->canmove_tick = tick;
				sd->skillitem = sd->skillitemlv = -1;
				return 0;
			}
		}
	}
	if(battle_config.pc_skill_nofootset) {
		range = -1;
		switch(sd->skillid) {
			case WZ_FIREPILLAR:
			case HT_SKIDTRAP:
			case HT_LANDMINE:
			case HT_ANKLESNARE:
			case HT_SHOCKWAVE:
			case HT_SANDMAN:
			case HT_FLASHER:
			case HT_FREEZINGTRAP:
			case HT_BLASTMINE:
			case HT_CLAYMORETRAP:
			case HT_TALKIEBOX:
				range = 1;
				break;
			case AL_WARP:
				range = 0;
				break;
		}
		if(range >= 0) {
			if(skill_check_unit_range2(sd->bl.m,sd->skillx,sd->skilly,range) > 0) {
				clif_skill_fail(sd,sd->skillid,0,0);
				sd->canact_tick = tick;
				sd->canmove_tick = tick;
				sd->skillitem = sd->skillitemlv = -1;
				return 0;
			}
		}
	}

	if(battle_config.pc_land_skill_limit) {
		maxcount = skill_get_maxcount(sd->skillid);
		if(maxcount > 0) {
			int i,c;
			for(i=c=0;i<MAX_SKILLUNITGROUP;i++) {
				if(sd->skillunit[i].alive_count > 0 && sd->skillunit[i].skill_id == sd->skillid)
					c++;
			}
			if(c >= maxcount) {
				clif_skill_fail(sd,sd->skillid,0,0);
				sd->canact_tick = tick;
				sd->canmove_tick = tick;
				sd->skillitem = sd->skillitemlv = -1;
				return 0;
			}
		}
	}

	range = skill_get_range(sd->skillid,sd->skilllv);
	if(range < 0)
		range = battle_get_range(&sd->bl) - (range + 1);
	range += battle_config.pc_skill_add_range;
	if(!battle_config.skill_out_range_consume) {
		if(range < distance(sd->bl.x,sd->bl.y,sd->skillx,sd->skilly)) {
			clif_skill_fail(sd,sd->skillid,0,0);
			sd->canact_tick = tick;
			sd->canmove_tick = tick;
			sd->skillitem = sd->skillitemlv = -1;
			return 0;
		}
	}
	if(!skill_check_condition(sd,1)) {		/* �g�p�����`�F�b�N */
		sd->canact_tick = tick;
		sd->canmove_tick = tick;
		sd->skillitem = sd->skillitemlv = -1;
		return 0;
	}
	sd->skillitem = sd->skillitemlv = -1;
	if(battle_config.skill_out_range_consume) {
		if(range < distance(sd->bl.x,sd->bl.y,sd->skillx,sd->skilly)) {
			clif_skill_fail(sd,sd->skillid,0,0);
			sd->canact_tick = tick;
			sd->canmove_tick = tick;
			return 0;
		}
	}

	if(battle_config.pc_skill_log)
		printf("PC %d skill castend skill=%d\n",sd->bl.id,sd->skillid);
	pc_stop_walking(sd,0);

	skill_castend_pos2(&sd->bl,sd->skillx,sd->skilly,sd->skillid,sd->skilllv,tick,0);

	return 0;
}

/*==========================================
 * �X�L���g�p�����i�U�Ŏg�p���s�j
 *------------------------------------------
 */
int skill_check_condition(struct map_session_data *sd,int type)
{
	int i,hp,sp,hp_rate,sp_rate,zeny,weapon,state,spiritball,skill,lv;
	int	index[10],itemid[10],amount[10];

	if( battle_config.gm_skilluncond>0 && pc_isGM(sd)>= battle_config.gm_skilluncond ) {
		sd->skillitem = sd->skillitemlv = -1;
		return 1;
	}

	if( sd->opt1>0) {
		clif_skill_fail(sd,sd->skillid,0,0);
		sd->skillitem = sd->skillitemlv = -1;
		return 0;
	}
	if(pc_is90overweight(sd)) {
		clif_skill_fail(sd,sd->skillid,9,0);
		sd->skillitem = sd->skillitemlv = -1;
		return 0;
	}

	if(sd->skillid == AC_MAKINGARROW &&	sd->state.make_arrow_flag == 1) {
		sd->skillitem = sd->skillitemlv = -1;
		return 0;
	}
	if(sd->skillid == AM_PHARMACY &&	sd->state.produce_flag == 1) {
		sd->skillitem = sd->skillitemlv = -1;
		return 0;
	}

	if(sd->skillitem == sd->skillid) {	/* �A�C�e���̏ꍇ���������� */
		if(type&1)
			sd->skillitem = sd->skillitemlv = -1;
		return 1;
	}
	if(sd->sc_data[SC_DIVINA].timer != -1 || sd->sc_data[SC_ROKISWEIL].timer != -1 || sd->sc_data[SC_STEELBODY].timer != -1) {
		clif_skill_fail(sd,sd->skillid,0,0);
		return 0;
	}
	if(sd->sc_data[SC_AUTOCOUNTER].timer != -1 && sd->skillid != KN_AUTOCOUNTER) {
		clif_skill_fail(sd,sd->skillid,0,0);
		return 0;
	}
	skill = sd->skillid;
	lv = sd->skilllv;
	hp=skill_get_hp(skill, lv);	/* ����HP */
	sp=skill_get_sp(skill, lv);	/* ����SP */
	hp_rate = (lv <= 0)? 0:skill_db[skill].hp_rate[lv-1];
	sp_rate = (lv <= 0)? 0:skill_db[skill].sp_rate[lv-1];
	zeny = skill_get_zeny(skill,lv);
	weapon = skill_db[skill].weapon;
	state = skill_db[skill].state;
	spiritball = (lv <= 0)? 0:skill_db[skill].spiritball[lv-1];
	for(i=0;i<10;i++) {
		itemid[i] = skill_db[skill].itemid[i];
		amount[i] = skill_db[skill].amount[i];
	}
	if(hp_rate > 0)
		hp += (sd->status.hp * hp_rate)/100;
	if(sp_rate > 0)
		sp += (sd->status.sp * sp_rate)/100;
	if(sd->dsprate!=100)
		sp=sp*sd->dsprate/100;	/* ����SP�C�� */

	switch(skill) {
	case SA_CASTCANCEL:
		if(sd->skilltimer == -1) {
			clif_skill_fail(sd,skill,0,0);
			return 0;
		}
		break;
	case BS_MAXIMIZE:		/* �}�L�V�}�C�Y�p���[ */
	case NV_TRICKDEAD:		/* ���񂾂ӂ� */
	case TF_HIDING:			/* �n�C�f�B���O */
	case AS_CLOAKING:		/* �N���[�L���O */
	case CR_AUTOGUARD:
	case CR_DEFENDER:
		if(sd->sc_data[SkillStatusChangeTable[skill]].timer!=-1)
			return 1;			/* ��������ꍇ��SP����Ȃ� */
		break;
	case AL_TELEPORT:
	case AL_WARP:
		if(map[sd->bl.m].flag.noteleport) {
			clif_skill_teleportmessage(sd,0);
			return 0;
		}
		break;
	case MO_CALLSPIRITS:
		if(sd->spiritball >= lv) {
			clif_skill_fail(sd,skill,0,0);
			return 0;
		}
		break;
	case MO_FINGEROFFENSIVE:				//�w�e
		if (sd->spiritball > 0 && sd->spiritball < spiritball) {
			spiritball = sd->spiritball;
			sd->spiritball_old = sd->spiritball;
		}
		else sd->spiritball_old = lv;
		break;
	case MO_CHAINCOMBO:						//�A�ŏ�
		if(sd->sc_data[SC_BLADESTOP].timer==-1){
			if(sd->sc_data[SC_COMBO].timer == -1 || sd->sc_data[SC_COMBO].val1 != MO_TRIPLEATTACK)
				return 0;
		}
		break;
	case MO_COMBOFINISH:					//�җ���
		if(sd->sc_data[SC_COMBO].timer == -1 || sd->sc_data[SC_COMBO].val1 != MO_CHAINCOMBO)
			return 0;
		break;
	case MO_EXTREMITYFIST:					// ���C���e�P��
		if((sd->sc_data[SC_COMBO].timer != -1 && sd->sc_data[SC_COMBO].val1 == MO_COMBOFINISH) || sd->sc_data[SC_BLADESTOP].timer!=-1)
			spiritball--;
		break;
	}

	if( hp>0 && sd->status.hp < hp) {				/* HP�`�F�b�N */
		clif_skill_fail(sd,skill,2,0);		/* HP�s���F���s�ʒm */
		return 0;
	}
	if( sp>0 && sd->status.sp < sp) {				/* SP�`�F�b�N */
		clif_skill_fail(sd,skill,1,0);		/* SP�s���F���s�ʒm */
		return 0;
	}
	if( zeny>0 && sd->status.zeny < zeny) {
		clif_skill_fail(sd,skill,5,0);
		return 0;
	}
	if(!(weapon & (1<<sd->status.weapon) ) ) {
		clif_skill_fail(sd,skill,6,0);
		return 0;
	}
	if( spiritball > 0 && sd->spiritball < spiritball) {
		clif_skill_fail(sd,skill,0,0);		// �����s��
		return 0;
	}

	switch(state) {
	case ST_HIDING:
		if(!(sd->status.option&2)) {
			clif_skill_fail(sd,skill,0,0);
			return 0;
		}
		break;
	case ST_CLOAKING:
		if(!(sd->status.option&4)) {
			clif_skill_fail(sd,skill,0,0);
			return 0;
		}
		break;
	case ST_HIDDEN:
		if(!pc_ishiding(sd)) {
			clif_skill_fail(sd,skill,0,0);
			return 0;
		}
		break;
	case ST_RIDING:
		if(!pc_isriding(sd)) {
			clif_skill_fail(sd,skill,0,0);
			return 0;
		}
		break;
	case ST_FALCON:
		if(!pc_isfalcon(sd)) {
			clif_skill_fail(sd,skill,0,0);
			return 0;
		}
		break;
	case ST_CART:
		if(!pc_iscarton(sd)) {
			clif_skill_fail(sd,skill,0,0);
			return 0;
		}
		break;
	case ST_SHIELD:
		if(sd->status.shield <= 0) {
			clif_skill_fail(sd,skill,0,0);
			return 0;
		}
		break;
	case ST_SIGHT:
		if(sd->sc_data[SC_SIGHT].timer == -1) {
			clif_skill_fail(sd,skill,0,0);
			return 0;
		}
		break;
	case ST_EXPLOSIONSPIRITS:
		if(sd->sc_data[SC_EXPLOSIONSPIRITS].timer == -1) {
			clif_skill_fail(sd,skill,0,0);
			return 0;
		}
		break;
	case ST_RECOV_WEIGHT_RATE:
		if(battle_config.natural_heal_weight_rate <= 100 && sd->weight*100/sd->max_weight >= battle_config.natural_heal_weight_rate) {
			clif_skill_fail(sd,skill,0,0);
			return 0;
		}
		break;
	case ST_MOVE_ENABLE:
		{
			struct walkpath_data wpd;
			if(path_search(&wpd,sd->bl.m,sd->bl.x,sd->bl.y,sd->skillx,sd->skilly,1)==-1) {
				clif_skill_fail(sd,skill,0,0);
				return 0;
			}
		}
		break;
	case ST_WATER:
		if(map_getcell(sd->bl.m,sd->bl.x,sd->bl.y) != 3){	//���ꔻ��
			clif_skill_fail(sd,skill,0,0);
			return 0;
		}
		break;
	}

	for(i=0;i<10;i++) {
		int x = lv%11 - 1;
		index[i] = -1;
		if(itemid[i] <= 0)
			continue;
		if(itemid[i] >= 715 && itemid[i] <= 717 && sd->special_state.no_gemstone)
			continue;
		if(((itemid[i] >= 715 && itemid[i] <= 717) || itemid[i] == 1065) && sd->sc_data[SC_INTOABYSS].timer != -1)
			continue;
		if(skill == AM_POTIONPITCHER && i != x)
			continue;

		index[i] = pc_search_inventory(sd,itemid[i]);
		if(index[i] < 0 || sd->status.inventory[index[i]].amount < amount[i]) {
			if(itemid[i] == 716 || itemid[i] == 717)
				clif_skill_fail(sd,skill,(7+(itemid[i]-716)),0);
			else
				clif_skill_fail(sd,skill,0,0);
			return 0;
		}
	}

	if(!(type&1))
		return 1;

	if(sp > 0) {					// SP����
		sd->status.sp-=sp;
		clif_updatestatus(sd,SP_SP);
	}
	if(hp > 0) {					// HP����
		sd->status.hp-=hp;
		clif_updatestatus(sd,SP_HP);
	}
	if(zeny > 0)					// Zeny����
		pc_payzeny(sd,zeny);
	if(spiritball > 0)				// ��������
		pc_delspiritball(sd,spiritball,0);

	if(skill != AM_POTIONPITCHER) {
		for(i=0;i<10;i++) {
			if(index[i] >= 0)
				pc_delitem(sd,index[i],amount[i],0);		// �A�C�e������
		}
	}
	return 1;
}

/*==========================================
 * �r�����Ԍv�Z
 *------------------------------------------
 */
int skill_castfix( struct block_list *bl, int time )
{
	struct status_change *sc_data = battle_get_sc_data(bl);
	int dex=battle_get_dex(bl);
	int castrate=100;
	if(time==0)
		return 0;
	if(bl->type==BL_PC) {
		castrate=((struct map_session_data *)bl)->castrate;
		time=time*castrate*(150- dex)/15000;
		time=time*battle_config.cast_rate/100;
	}

	/* �T�t���M�E�� */
	if(sc_data && sc_data[SC_SUFFRAGIUM].timer!=-1 ){
		time=time*(100-sc_data[SC_SUFFRAGIUM].val1*15)/100;
		skill_status_change_end( bl, SC_SUFFRAGIUM, -1);
	}
	/* �u���M�̎� */
	if(sc_data && sc_data[SC_POEMBRAGI].timer!=-1 )
		time=time*(100-(sc_data[SC_POEMBRAGI].val1*3+sc_data[SC_POEMBRAGI].val2
				+(sc_data[SC_POEMBRAGI].val3>>16)))/100;

	return (time>0)?time:0;
}
/*==========================================
 * �f�B���C�v�Z
 *------------------------------------------
 */
int skill_delayfix( struct block_list *bl, int time )
{
	struct status_change *sc_data = battle_get_sc_data(bl);
	if(time<=0)
		return 0;

	if(bl->type == BL_PC) {
		if( battle_config.delay_dependon_dex )	/* dex�̉e�����v�Z���� */
			time=time*(150- battle_get_dex(bl))/150;
		time=time*battle_config.delay_rate/100;
	}

	/* �u���M�̎� */
	if(sc_data && sc_data[SC_POEMBRAGI].timer!=-1 )
		time=time*(100-(sc_data[SC_POEMBRAGI].val1*3+sc_data[SC_POEMBRAGI].val2
				+(sc_data[SC_POEMBRAGI].val3&0xffff)))/100;

	return (time>0)?time:0;
}
/*==========================================
 * �X�L���g�p�iID�w��j
 *------------------------------------------
 */
int skill_use_id( struct map_session_data *sd, int target_id,
	int skill_num, int skill_lv)
{
	unsigned int tick;
	int casttime=0,delay=0,skill,range;
	struct map_session_data* target_sd=NULL;
	int forcecast=0;
	struct block_list *bl;
	tick=gettick();

	bl=map_id2bl(target_id);
	if(bl==NULL){
/*		if(battle_config.error_log)
			printf("skill target not found %d\n",target_id); */
		return 0;
	}
	if(sd->bl.m != bl->m || pc_isdead(sd))
		return 0;

	/* ���ق�ُ�i�������A�O�����Ȃǂ̔��������j */
	if( sd->opt1>0 ||  sd->sc_data[SC_DIVINA].timer!=-1 || sd->sc_data[SC_ROKISWEIL].timer!=-1 || sd->sc_data[SC_STEELBODY].timer != -1)
		return 0;
	if(sd->sc_data[SC_AUTOCOUNTER].timer != -1 && sd->skillid != KN_AUTOCOUNTER)
		return 0;
	if(sd->sc_data[SC_BLADESTOP].timer != -1){
		int lv = sd->sc_data[SC_BLADESTOP].val1;
		if(sd->sc_data[SC_BLADESTOP].val2==1) return 0;//���H���ꂽ���Ȃ̂Ń_��
		if(lv==1) return 0;
		if(lv==2 && skill_num!=MO_FINGEROFFENSIVE) return 0;
		if(lv==3 && skill_num!=MO_FINGEROFFENSIVE && skill_num!=MO_INVESTIGATE) return 0;
		if(lv==4 && skill_num!=MO_FINGEROFFENSIVE && skill_num!=MO_INVESTIGATE && skill_num!=MO_CHAINCOMBO) return 0;
		if(lv==5 && skill_num!=MO_FINGEROFFENSIVE && skill_num!=MO_INVESTIGATE && skill_num!=MO_CHAINCOMBO && skill_num!=MO_EXTREMITYFIST) return 0;
	}

	if(sd->status.option&4 && skill_num==TF_HIDING)
		return 0;
	if(sd->status.option&2 && skill_num!=TF_HIDING && skill_num!=AS_GRIMTOOTH && skill_num!=RG_BACKSTAP && skill_num!=RG_RAID )
		return 0;

	if(map[sd->bl.m].flag.gvg && (skill_num == SM_ENDURE || skill_num == AL_TELEPORT || skill_num == AL_WARP ||
		skill_num == WZ_ICEWALL || skill_num == TF_BACKSLIDING))
		return 0;

	/* ���t/�_���X�� */
	if( sd->sc_data[SC_DANCING].timer!=-1 && skill_num!=BD_ADAPTATION &&
		skill_num!=BA_MUSICALSTRIKE && skill_num!=DC_THROWARROW ){
//		if(battle_config.pc_skill_log)
//			printf("dancing! %d\n",skill_num);
		return 0;
	}

	if(skill_get_inf2(skill_num)&0x200 && sd->bl.id == target_id)
		return 0;

	sd->skillid = skill_num;
	sd->skilllv = skill_lv;
	if(!skill_check_condition(sd,0)) return 0;

	if(skill_num == SA_CASTCANCEL) {
		sd->skillid_old = sd->skillid;
		sd->skilllv_old = sd->skilllv;
	}

	/* �˒��Ə�Q���`�F�b�N */
	range = skill_get_range(skill_num,skill_lv);
	if(range < 0)
		range = battle_get_range(&sd->bl) - (range + 1);
	if(!battle_check_range(&sd->bl,bl,range) )
		return 0;

	if(bl->type==BL_PC) {
		target_sd=(struct map_session_data*)bl;
		if(skill_num == ALL_RESURRECTION && !pc_isdead(target_sd))
			return 0;
	}
	if((skill_num != MO_CHAINCOMBO && skill_num != MO_COMBOFINISH && skill_num != MO_EXTREMITYFIST) ||
		(skill_num == MO_EXTREMITYFIST && sd->state.skill_flag) )
		pc_stopattack(sd);

	casttime=skill_castfix(&sd->bl, skill_get_cast( skill_num,skill_lv) );
	if(skill_num != SA_MAGICROD)
		delay=skill_delayfix(&sd->bl, skill_get_delay( skill_num,skill_lv) );
	sd->state.skillcastcancel = skill_db[skill_num].castcancel;

	switch(skill_num){	/* ��������ȏ������K�v */
//	case AL_HEAL:	/* �q�[�� */
//		if(battle_check_undead(battle_get_race(bl),battle_get_elem_type(bl)))
//			forcecast=1;	/* �q�[���A�^�b�N�Ȃ�r���G�t�F�N�g�L�� */
//		break;
	case ALL_RESURRECTION:	/* ���U���N�V���� */
		if(bl->type != BL_PC && battle_check_undead(battle_get_race(bl),battle_get_elem_type(bl))){	/* �G���A���f�b�h�Ȃ� */
			forcecast=1;	/* �^�[���A���f�b�g�Ɠ����r������ */
			casttime=skill_castfix(&sd->bl, skill_get_cast(PR_TURNUNDEAD,skill_lv) );
		}
		break;
	case MO_FINGEROFFENSIVE:	/* �w�e */
		casttime += casttime * ((skill_lv > sd->spiritball)? sd->spiritball:skill_lv);
		break;
	case MO_CHAINCOMBO:		/*�A�ŏ�*/
		target_id = sd->attacktarget;
		if(sd->sc_data[SC_BLADESTOP].timer!=-1)
			target_id = ((struct block_list *)sd->sc_data[SC_BLADESTOP].val4)->id;
		break;
	case MO_COMBOFINISH:		/*�җ���*/
		target_id = sd->attacktarget;
		break;
	case MO_EXTREMITYFIST:	/*���C���e�P��*/
		if(sd->sc_data[SC_COMBO].timer != -1 && sd->sc_data[SC_COMBO].val1 == MO_COMBOFINISH) {
			casttime = 0;
			target_id = sd->attacktarget;
		}
		forcecast=1;
		break;
	case SA_MAGICROD:
	case SA_SPELLBREAKER:
		forcecast=1;
		break;
	}

	if(battle_config.pc_skill_log)
		printf("PC %d skill use target_id=%d skill=%d lv=%d cast=%d\n",sd->bl.id,target_id,skill_num,skill_lv,casttime);

//	if(sd->skillitem == skill_num)
//		casttime = delay = 0;

	if( casttime>0 || forcecast ){ /* �r�����K�v */
		struct mob_data *md;
		clif_skillcasting( &sd->bl,
			sd->bl.id, target_id, 0,0, skill_num,casttime);

		/* �r�����������X�^�[ */
		if( bl->type==BL_MOB && mob_db[(md=(struct mob_data *)bl)->class].mode&0x10 &&
			md->state.state!=MS_ATTACK && sd->invincible_timer == -1){
				md->target_id=sd->bl.id;
				md->state.targettype = ATTACKABLE;
				md->min_chase=13;
		}
	}

	if( casttime<=0 )	/* �r���̖������̂̓L�����Z������Ȃ� */
		sd->state.skillcastcancel=0;

	sd->skilltarget	= target_id;
/*	sd->cast_target_bl	= bl; */
	sd->skillx		= 0;
	sd->skilly		= 0;
	sd->canact_tick = tick + casttime + delay;
	sd->canmove_tick = tick;
	if(!(battle_config.pc_cloak_check_type&2) && sd->sc_data[SC_CLOAKING].timer != -1 && sd->skillid != AS_CLOAKING)
		skill_status_change_end(&sd->bl,SC_CLOAKING,-1);
	if(casttime > 0) {
		sd->skilltimer = add_timer( tick+casttime, skill_castend_id, sd->bl.id, 0 );
		if((skill = pc_checkskill(sd,SA_FREECAST)) > 0) {
			sd->prev_speed = sd->speed;
			sd->speed = sd->speed*(175 - skill*5)/100;
			clif_updatestatus(sd,SP_SPEED);
		}
		else
			pc_stop_walking(sd,0);
	}
	else {
		if(skill_num != SA_CASTCANCEL)
			sd->skilltimer = -1;
		skill_castend_id(sd->skilltimer,tick,sd->bl.id,0);
	}

	return 0;
}

/*==========================================
 * �X�L���g�p�i�ꏊ�w��j
 *------------------------------------------
 */
int skill_use_pos( struct map_session_data *sd,
	int skill_x, int skill_y, int skill_num, int skill_lv)
{
	struct block_list bl;
	unsigned int tick;
	int casttime=0,delay=0,skill,range;

	if(pc_isdead(sd))
		return 0;

	if( sd->opt1>0 || sd->sc_data[SC_DIVINA].timer!=-1 || sd->sc_data[SC_ROKISWEIL].timer!=-1 ||
		sd->sc_data[SC_AUTOCOUNTER].timer != -1 || sd->sc_data[SC_STEELBODY].timer != -1)
		return 0;	/* �ُ�Ⓘ�قȂ� */

	if(sd->status.option&2)
		return 0;

	if(map[sd->bl.m].flag.gvg && (skill_num == SM_ENDURE || skill_num == AL_TELEPORT || skill_num == AL_WARP ||
		skill_num == WZ_ICEWALL || skill_num == TF_BACKSLIDING))
		return 0;

	/* ���t/�_���X�����`�F�b�N */
	if( sd->sc_data[SC_DANCING].timer!=-1 )
		return 0;

	sd->skillid = skill_num;
	sd->skilllv = skill_lv;
	sd->skillx = skill_x;
	sd->skilly = skill_y;
	if(!skill_check_condition(sd,0)) return 0;

	/* �˒��Ə�Q���`�F�b�N */
	bl.type = BL_NUL;
	bl.m = sd->bl.m;
	bl.x = skill_x;
	bl.y = skill_y;
	range = skill_get_range(skill_num,skill_lv);
	if(range < 0)
		range = battle_get_range(&sd->bl) - (range + 1);
	if(!battle_check_range(&sd->bl,&bl,range) )
		return 0;

	pc_stopattack(sd);

	casttime=skill_castfix(&sd->bl, skill_get_cast( skill_num,skill_lv) );
	delay=skill_delayfix(&sd->bl, skill_get_delay( skill_num,skill_lv) );
	sd->state.skillcastcancel = skill_db[skill_num].castcancel;

	if(battle_config.pc_skill_log)
		printf("PC %d skill use target_pos=(%d,%d) skill=%d lv=%d cast=%d\n",sd->bl.id,skill_x,skill_y,skill_num,skill_lv,casttime);

//	if(sd->skillitem == skill_num)
//		casttime = delay = 0;

	if( casttime>0 )	/* �r�����K�v */
		clif_skillcasting( &sd->bl,
			sd->bl.id, 0, skill_x,skill_y, skill_num,casttime);

	if( casttime<=0 )	/* �r���̖������̂̓L�����Z������Ȃ� */
		sd->state.skillcastcancel=0;

	sd->skilltarget	= 0;
/*	sd->cast_target_bl	= NULL; */
	tick=gettick();
	sd->canact_tick = tick + casttime + delay;
	sd->canmove_tick = tick;
	if(!(battle_config.pc_cloak_check_type&2) && sd->sc_data[SC_CLOAKING].timer != -1)
		skill_status_change_end(&sd->bl,SC_CLOAKING,-1);
	if(casttime > 0) {
		sd->skilltimer = add_timer( tick+casttime, skill_castend_pos, sd->bl.id, 0 );
		if((skill = pc_checkskill(sd,SA_FREECAST)) > 0) {
			sd->prev_speed = sd->speed;
			sd->speed = sd->speed*(175 - skill*5)/100;
			clif_updatestatus(sd,SP_SPEED);
		}
		else
			pc_stop_walking(sd,0);
	}
	else {
		sd->skilltimer = -1;
		skill_castend_pos(sd->skilltimer,tick,sd->bl.id,0);
	}

	return 0;
}

/*==========================================
 * �X�L���r���L�����Z��
 *------------------------------------------
 */
int skill_castcancel(struct block_list *bl,int type)
{
	int inf;
	if(bl->type==BL_PC){
		struct map_session_data *sd=(struct map_session_data *)bl;
		unsigned long tick=gettick();
		sd->canact_tick=tick;
		sd->canmove_tick = tick;
		if( sd->skilltimer!=-1){
			if(pc_checkskill(sd,SA_FREECAST) > 0) {
				sd->speed = sd->prev_speed;
				clif_updatestatus(sd,SP_SPEED);
			}
			if(!type) {
				if((inf = skill_get_inf( sd->skillid )) == 2 || inf == 32)
					delete_timer( sd->skilltimer, skill_castend_pos );
				else
					delete_timer( sd->skilltimer, skill_castend_id );
			}
			else {
				if((inf = skill_get_inf( sd->skillid_old )) == 2 || inf == 32)
					delete_timer( sd->skilltimer, skill_castend_pos );
				else
					delete_timer( sd->skilltimer, skill_castend_id );
			}
			sd->skilltimer=-1;
			clif_skillcastcancel(bl);
		}

		return 0;
	}else if(bl->type==BL_MOB){
		struct mob_data *md=(struct mob_data *)bl;
		if( md->skilltimer!=-1 ){
			if((inf = skill_get_inf( md->skillid )) == 2 || inf == 32)
				delete_timer( md->skilltimer, mobskill_castend_pos );
			else
				delete_timer( md->skilltimer, mobskill_castend_id );
			md->skilltimer=-1;
			clif_skillcastcancel(bl);
		}
		return 0;
	}
	return 1;
}
/*=========================================
 * �u�����f�B�b�V���X�s�A �����͈͌���
 *----------------------------------------
 */
void skill_brandishspear_first(struct square *tc,int dir,int x,int y){
	if(dir == 0){
		tc->val1[0]=x-2;
		tc->val1[1]=x-1;
		tc->val1[2]=x;
		tc->val1[3]=x+1;
		tc->val1[4]=x+2;
		tc->val2[0]=
		tc->val2[1]=
		tc->val2[2]=
		tc->val2[3]=
		tc->val2[4]=y-1;
	}
	else if(dir==2){
		tc->val1[0]=
		tc->val1[1]=
		tc->val1[2]=
		tc->val1[3]=
		tc->val1[4]=x+1;
		tc->val2[0]=y+2;
		tc->val2[1]=y+1;
		tc->val2[2]=y;
		tc->val2[3]=y-1;
		tc->val2[4]=y-2;
	}
	else if(dir==4){
		tc->val1[0]=x-2;
		tc->val1[1]=x-1;
		tc->val1[2]=x;
		tc->val1[3]=x+1;
		tc->val1[4]=x+2;
		tc->val2[0]=
		tc->val2[1]=
		tc->val2[2]=
		tc->val2[3]=
		tc->val2[4]=y+1;
	}
	else if(dir==6){
		tc->val1[0]=
		tc->val1[1]=
		tc->val1[2]=
		tc->val1[3]=
		tc->val1[4]=x-1;
		tc->val2[0]=y+2;
		tc->val2[1]=y+1;
		tc->val2[2]=y;
		tc->val2[3]=y-1;
		tc->val2[4]=y-2;
	}
	else if(dir==1){
		tc->val1[0]=x-1;
		tc->val1[1]=x;
		tc->val1[2]=x+1;
		tc->val1[3]=x+2;
		tc->val1[4]=x+3;
		tc->val2[0]=y-4;
		tc->val2[1]=y-3;
		tc->val2[2]=y-1;
		tc->val2[3]=y;
		tc->val2[4]=y+1;
	}
	else if(dir==3){
		tc->val1[0]=x+3;
		tc->val1[1]=x+2;
		tc->val1[2]=x+1;
		tc->val1[3]=x;
		tc->val1[4]=x-1;
		tc->val2[0]=y-1;
		tc->val2[1]=y;
		tc->val2[2]=y+1;
		tc->val2[3]=y+2;
		tc->val2[4]=y+3;
	}
	else if(dir==5){
		tc->val1[0]=x+1;
		tc->val1[1]=x;
		tc->val1[2]=x-1;
		tc->val1[3]=x-2;
		tc->val1[4]=x-3;
		tc->val2[0]=y+3;
		tc->val2[1]=y+2;
		tc->val2[2]=y+1;
		tc->val2[3]=y;
		tc->val2[4]=y-1;
	}
	else if(dir==7){
		tc->val1[0]=x-3;
		tc->val1[1]=x-2;
		tc->val1[2]=x-1;
		tc->val1[3]=x;
		tc->val1[4]=x+1;
		tc->val2[1]=y;
		tc->val2[0]=y+1;
		tc->val2[2]=y-1;
		tc->val2[3]=y-2;
		tc->val2[4]=y-3;
	}

}

/*=========================================
 * �u�����f�B�b�V���X�s�A �������� �͈͊g��
 *-----------------------------------------
 */
void skill_brandishspear_dir(struct square *tc,int dir,int are){

	int c;

	for(c=0;c<5;c++){
		if(dir==0){
			tc->val2[c]+=are;
		}else if(dir==1){
			tc->val1[c]-=are; tc->val2[c]+=are;
		}else if(dir==2){
			tc->val1[c]-=are;
		}else if(dir==3){
			tc->val1[c]-=are; tc->val2[c]-=are;
		}else if(dir==4){
			tc->val2[c]-=are;
		}else if(dir==5){
			tc->val1[c]+=are; tc->val2[c]-=are;
		}else if(dir==6){
			tc->val1[c]+=are;
		}else if(dir==7){
			tc->val1[c]+=are; tc->val2[c]+=are;
		}
	}
}

/*==========================================
 * �f�B�{�[�V���� �L���m�F
 *------------------------------------------
 */
void skill_devotion(struct map_session_data *md,int target)
{
	// ���m�F
	int n;
	for(n=0;n<5;n++){
		if(md && md->dev.val1[n]){
			struct map_session_data *sd = map_id2sd(md->dev.val1[n]);
			// ���肪������Ȃ� // ������f�B�{���Ă�̂���������Ȃ� // ����������Ă�
			if(!sd || md->bl.id != sd->sc_data[SC_DEVOTION].val1 || skill_devotion3(&md->bl,md->dev.val1[n])){
				skill_devotion_end(md,sd,n);
			}
		}
	}
}
void skill_devotion2(struct block_list *bl,int crusader)
{
	// ��f�B�{�[�V���������������̋����`�F�b�N
	struct map_session_data *sd = map_id2sd(crusader);
	if(sd) skill_devotion3(&sd->bl,bl->id);
}
int skill_devotion3(struct block_list *bl,int target)
{
	// �N���Z�����������̋����`�F�b�N
	struct map_session_data *md = (struct map_session_data *)bl;
	struct map_session_data *sd = map_id2sd(target);
	int n,r=0;
	if(!md || !sd) return 1;
	else
		r = distance(bl->x,bl->y,sd->bl.x,sd->bl.y);

	if(pc_checkskill(sd,CR_DEVOTION)+6 < r){	// ���e�͈͂𒴂��Ă�
		for(n=0;n<5;n++)
			if(md->dev.val1[n]==target)
				md->dev.val2[n]=0;	// ���ꂽ���́A����؂邾��
		clif_devotion(md,sd->bl.id);
		return 1;
	}
	return 0;
}

void skill_devotion_end(struct map_session_data *md,struct map_session_data *sd,int target)
{
	// �N���Z�Ɣ�f�B�{�L�����̃��Z�b�g
	md->dev.val1[target]=md->dev.val2[target]=0;
	if(sd){
	//	skill_status_change_end(sd->bl,SC_DEVOTION,-1);
		sd->sc_data[SC_DEVOTION].val1=0;
		sd->sc_data[SC_DEVOTION].val2=0;
		clif_status_change(&sd->bl,SC_DEVOTION,0);
		clif_devotion(md,sd->bl.id);
	}
}
/*==========================================
 * �I�[�g�X�y��
 *------------------------------------------
 */
int skill_autospell(struct map_session_data *sd,int skillid)
{
	int skilllv = pc_checkskill(sd,SA_AUTOSPELL);
	int maxlv=1,lv;

	if(skillid==MG_NAPALMBEAT)	maxlv=3;
	else if(skillid==MG_COLDBOLT || skillid==MG_FIREBOLT || skillid==MG_LIGHTNINGBOLT){
		if(skilllv==2) maxlv=1;
		else if(skilllv==3) maxlv=2;
		else if(skilllv>=4) maxlv=3;
	}
	else if(skillid==MG_SOULSTRIKE){
		if(skilllv==5) maxlv=1;
		else if(skilllv==6) maxlv=2;
		else if(skilllv>=7) maxlv=3;
	}
	else if(skillid==MG_FIREBALL){
		if(skilllv==8) maxlv=1;
		else if(skilllv>=9) maxlv=2;
	}
	else if(skillid==MG_FROSTDIVER) maxlv=1;
	else return 0;

	if(maxlv > (lv=pc_checkskill(sd,skillid)))
		maxlv = lv;

	skill_status_change_start(&sd->bl,SC_AUTOSPELL,skilllv,skillid,maxlv,0,	// val1:�X�L��ID val2:�g�p�ő�Lv
		skill_get_time(SA_AUTOSPELL,skilllv),0);// �ɂ��Ă݂�����bscript�������Ղ��E�E�E�H
	return 0;
}

/*==========================================
 * �M�����O�X�^�[�p���_�C�X���菈��(foreachinarea)
 *------------------------------------------
 */

static int skill_gangster_count(struct block_list *bl,va_list ap)
{
	int *c;
	struct map_session_data *sd=(struct map_session_data*)bl;
	c=va_arg(ap,int *);

	if(pc_issit(sd) && pc_checkskill(sd,RG_GANGSTER) > 0)
		(*c)++;
	return 0;
}

static int skill_gangster_in(struct block_list *bl,va_list ap)
{
	struct map_session_data *sd=(struct map_session_data*)bl;

	if(pc_issit(sd) && pc_checkskill(sd,RG_GANGSTER) > 0)
		sd->state.gangsterparadise=1;
	return 0;
}

static int skill_gangster_out(struct block_list *bl,va_list ap)
{
	struct map_session_data *sd=(struct map_session_data*)bl;
	if(sd->state.gangsterparadise)
		sd->state.gangsterparadise=0;
	return 0;
}

int skill_gangsterparadise(struct map_session_data *sd ,int type)
{
	int range=1;
	int c=0;

	if(pc_checkskill(sd,RG_GANGSTER) <= 0)
		return 0;

	if(type==1) {/* ���������̏��� */
		map_foreachinarea(skill_gangster_count,sd->bl.m,
			sd->bl.x-range,sd->bl.y-range,
			sd->bl.x+range,sd->bl.y+range,BL_PC,&c);
		if(c > 1) {/*�M�����O�X�^�[���������玩���ɂ��M�����O�X�^�[�����t�^*/
			map_foreachinarea(skill_gangster_in,sd->bl.m,
				sd->bl.x-range,sd->bl.y-range,
				sd->bl.x+range,sd->bl.y+range,BL_PC);
			sd->state.gangsterparadise = 1;
		}
		return 0;
	}
	else if(type==0) {/* �����オ�����Ƃ��̏��� */
		map_foreachinarea(skill_gangster_count,sd->bl.m,
			sd->bl.x-range,sd->bl.y-range,
			sd->bl.x+range,sd->bl.y+range,BL_PC,&c);
		if(c < 2)
			map_foreachinarea(skill_gangster_out,sd->bl.m,
				sd->bl.x-range,sd->bl.y-range,
				sd->bl.x+range,sd->bl.y+range,BL_PC);
		sd->state.gangsterparadise = 0;
		return 0;
	}
	return 0;
}
/*==========================================
 * �����W���[�N�E�X�N���[�����菈��(foreachinarea)
 *------------------------------------------
 */
int skill_frostjoke_scream(struct block_list *bl,va_list ap)
{
	struct block_list *src;
	int skillnum,skilllv;
	unsigned int tick;

	src=va_arg(ap,struct block_list*);
	skillnum=va_arg(ap,int);
	skilllv=va_arg(ap,int);
	tick=va_arg(ap,unsigned int);

	if(src == bl)//�����ɂ͌����Ȃ�
		return 0;

	if(battle_check_target(src,bl,BCT_ENEMY) > 0)
		skill_additional_effect(src,bl,skillnum,skilllv,BF_MISC,tick);
	else if(battle_check_target(src,bl,BCT_PARTY) > 0) {
		if(rand()%100 < 10)//PT�����o�ɂ���m���ł�����(�Ƃ肠����10%)
			skill_additional_effect(src,bl,skillnum,skilllv,BF_MISC,tick);
	}

	return 0;
}

/*==========================================
 *�A�u���J�_�u���̎g�p�X�L������(����X�L�����_���Ȃ�0��Ԃ�)
 *------------------------------------------
 */
int skill_abra_dataset(int skilllv)
{
	int skill = rand()%331;
	//db�Ɋ�Â����x���E�m������
	if(skill_abra_db[skill].req_lv > skilllv || rand()%10000 >= skill_abra_db[skill].per) return 0;
	//NPC�X�L���̓_��
	if(skill >= NPC_PIERCINGATT && skill <= NPC_SUMMONMONSTER) return 0;
	//���t�X�L���̓_��
	if(skill_is_danceskill(skill)) return 0;

	return skill;
}

/*==========================================
 *
 *------------------------------------------
 */
int skill_attack_area(struct block_list *bl,va_list ap)
{
	struct block_list *src,*dsrc;
	int atk_type,skillid,skilllv,flag,type;
	unsigned int tick;

	atk_type = va_arg(ap,int);
	src=va_arg(ap,struct block_list*);
	dsrc=va_arg(ap,struct block_list*);
	skillid=va_arg(ap,int);
	skilllv=va_arg(ap,int);
	tick=va_arg(ap,unsigned int);
	flag=va_arg(ap,int);
	type=va_arg(ap,int);

	if(battle_check_target(dsrc,bl,type) > 0)
		skill_attack(atk_type,src,dsrc,bl,skillid,skilllv,tick,flag);

	return 0;
}
/*==========================================
 *
 *------------------------------------------
 */
int skill_clear_element_field(struct block_list *bl)
{
	struct mob_data *md=NULL;
	struct map_session_data *sd=NULL;
	int i,skillid;

	if(bl->type==BL_MOB)
		md=(struct mob_data *)bl;
	if(bl->type==BL_PC)
		sd=(struct map_session_data *)bl;

	for(i=0;i<MAX_MOBSKILLUNITGROUP;i++){
		if(sd){
			skillid=sd->skillunit[i].skill_id;
			if(skillid==SA_DELUGE||skillid==SA_VOLCANO||skillid==SA_VIOLENTGALE||skillid==SA_LANDPROTECTOR)
				skill_delunitgroup(&sd->skillunit[i]);
		}else if(md){
			skillid=md->skillunit[i].skill_id;
			if(skillid==SA_DELUGE||skillid==SA_VOLCANO||skillid==SA_VIOLENTGALE||skillid==SA_LANDPROTECTOR)
				skill_delunitgroup(&md->skillunit[i]);
		}
	}
	return 0;
}
/*==========================================
 * �����h�v���e�N�^�[�`�F�b�N(foreachinarea)
 *------------------------------------------
 */
int skill_landprotector(struct block_list *bl, va_list ap )
{
	int skillid=va_arg(ap,int);
	int *alive=va_arg(ap,int *);
	struct skill_unit *unit=(struct skill_unit *)bl;

	if(skillid==SA_LANDPROTECTOR){
		skill_delunit(unit);
	}else{
		if(unit->group->skill_id==SA_LANDPROTECTOR)
			(*alive)=0;
	}
	return 0;
}
/*==========================================
 * �C�h�D���̗ь�̉񕜏���(foreachinarea)
 *------------------------------------------
 */
int skill_idun_heal(struct block_list *bl, va_list ap )
{
	struct skill_unit *unit = va_arg(ap,struct skill_unit *);
	struct skill_unit_group *sg = unit->group;
	int heal=30+sg->skill_lv*5+((sg->val1)>>16)*5+((sg->val1)&0xfff)/2;

	if(bl->type == BL_SKILL || bl->id == sg->src_id)
		return 0;
	
	clif_skill_nodamage(&unit->bl,bl,AL_HEAL,heal,1);
	battle_heal(NULL,bl,heal,0,0);

	return 0;
}

/*----------------------------------------------------------------------------
 * �X�e�[�^�X�ُ�
 *----------------------------------------------------------------------------
 */

/*==========================================
 * �X�e�[�^�X�ُ�^�C�}�[�͈͏���
 *------------------------------------------
 */
int skill_status_change_timer_sub(struct block_list *bl, va_list ap )
{
	struct block_list *src;
	int type;
	unsigned int tick;
	src=va_arg(ap,struct block_list*);
	type=va_arg(ap,int);
	tick=va_arg(ap,unsigned int);

	if(bl->type!=BL_PC && bl->type!=BL_MOB)
		return 0;

	switch( type ){
	case SC_SIGHT:	/* �T�C�g */
	case SC_CONCENTRATE:
		if( (*battle_get_option(bl))&6 ){
			skill_status_change_end( bl, SC_HIDING, -1);
			skill_status_change_end( bl, SC_CLOAKING, -1);
		}
		break;
	case SC_RUWACH:	/* ���A�t */
		if( (*battle_get_option(bl))&6 ){
			skill_status_change_end( bl, SC_HIDING, -1);
			skill_status_change_end( bl, SC_CLOAKING, -1);
			if(battle_check_target( src,bl, BCT_ENEMY ) > 0) {
				struct status_change *sc_data = battle_get_sc_data(bl);
				skill_attack(BF_MAGIC,src,src,bl,AL_RUWACH,sc_data[type].val1,tick,0);
			}
		}
		break;
	}
	return 0;
}

/*==========================================
 * �X�e�[�^�X�ُ�I��
 *------------------------------------------
 */
int skill_status_change_end( struct block_list* bl , int type,int tid )
{
	struct status_change* sc_data;
	int opt_flag=0, calc_flag = 0;
	short *sc_count, *option, *opt1, *opt2;

	sc_data=battle_get_sc_data(bl);
	sc_count=battle_get_sc_count(bl);
	option=battle_get_option(bl);
	opt1=battle_get_opt1(bl);
	opt2=battle_get_opt2(bl);

	if(bl->type!=BL_PC && bl->type!=BL_MOB) {
		if(battle_config.error_log)
			printf("skill_status_change_end: neither MOB nor PC !\n");
		return 0;
	}

	if((*sc_count)>0 && sc_data[type].timer!=-1 &&
		(sc_data[type].timer==tid || tid==-1) ){

		if(tid==-1)	/* �^�C�}����Ă΂�Ă��Ȃ��Ȃ�^�C�}�폜������ */
			delete_timer(sc_data[type].timer,skill_status_change_timer);

		/* �Y���ُ̈�𐳏�ɖ߂� */
		sc_data[type].timer=-1;
		(*sc_count)--;

		switch(type){	/* �ُ�̎�ނ��Ƃ̏��� */
			case SC_PROVOKE:			/* �v���{�b�N */
			case SC_CONCENTRATE:		/* �W���͌��� */
			case SC_BLESSING:			/* �u���b�V���O */
			case SC_ANGELUS:			/* �A���[���X */
			case SC_INCREASEAGI:		/* ���x�㏸ */
			case SC_DECREASEAGI:		/* ���x���� */
			case SC_SIGNUMCRUCIS:		/* �V�O�i���N���V�X */
			case SC_HIDING:
			case SC_TWOHANDQUICKEN:		/* 2HQ */
			case SC_ADRENALINE:			/* �A�h���i�������b�V�� */
			case SC_ENCPOISON:			/* �G���`�����g�|�C�Y�� */
			case SC_IMPOSITIO:			/* �C���|�V�e�B�I�}�k�X */
			case SC_GLORIA:				/* �O�����A */
			case SC_LOUD:				/* ���E�h�{�C�X */
			case SC_QUAGMIRE:			/* �N�@�O�}�C�A */
			case SC_PROVIDENCE:			/* �v�����B�f���X */
			case SC_SPEARSQUICKEN:		/* �X�s�A�N�C�b�P�� */
			case SC_VOLCANO:
			case SC_DELUGE:
			case SC_VIOLENTGALE:
			case SC_ETERNALCHAOS:		/* �G�^�[�i���J�I�X */
			case SC_DRUMBATTLE:			/* �푾�ۂ̋��� */
			case SC_NIBELUNGEN:			/* �j�[�x�����O�̎w�� */
			case SC_SIEGFRIED:			/* �s���g�̃W�[�N�t���[�h */
			case SC_WHISTLE:			/* ���J */
			case SC_ASSNCROS:			/* �[�z�̃A�T�V���N���X */
			case SC_HUMMING:			/* �n�~���O */
			case SC_DONTFORGETME:		/* ����Y��Ȃ��� */
			case SC_FORTUNE:			/* �K�^�̃L�X */
			case SC_SERVICE4U:			/* �T�[�r�X�t�H�[���[ */
			case SC_EXPLOSIONSPIRITS:	// �����g��
			case SC_STEELBODY:			// ����
			case SC_DEFENDER:
			case SC_SPEEDPOTION0:		/* �����|�[�V���� */
			case SC_SPEEDPOTION1:
			case SC_SPEEDPOTION2:
			case SC_APPLEIDUN:			/* �C�h�D���̗ь� */
			case SC_DANCING:			/* �_���X/���t�� */
			case SC_RIDING:
			case SC_BLADESTOP_WAIT:
				calc_flag = 1;
				break;

			case SC_DEVOTION:		/* �f�B�{�[�V���� */
				{
					struct map_session_data *md = map_id2sd(sc_data[type].val1);
					sc_data[type].val1=sc_data[type].val2=0;
					skill_devotion(md,bl->id);
					calc_flag = 1;
				}
				break;
			case SC_BLADESTOP:
				{
					struct status_change *t_sc_data = battle_get_sc_data((struct block_list *)sc_data[type].val4);
					//�Е����؂ꂽ�̂ő���̔��n��Ԃ��؂�ĂȂ��̂Ȃ����
					if(t_sc_data && t_sc_data[SC_BLADESTOP].timer!=-1)
						skill_status_change_end((struct block_list *)sc_data[type].val4,SC_BLADESTOP,-1);

					if(sc_data[type].val2==2)
						clif_bladestop((struct block_list *)sc_data[type].val3,(struct block_list *)sc_data[type].val4,0);
				}
				break;

		/* option1 */
			case SC_FREEZE:
				sc_data[type].val3 = 0;
				break;

		/* option2 */
			case SC_POISON:				/* �� */
			case SC_BLIND:				/* �Í� */
			case SC_CURSE:
				calc_flag = 1;
				break;
		}

		if(bl->type==BL_PC && type<SC_SENDMAX)
			clif_status_change(bl,type,0);	/* �A�C�R������ */

		switch(type){	/* ����ɖ߂�Ƃ��Ȃɂ��������K�v */
		case SC_STONE:
		case SC_FREEZE:
		case SC_STAN:
		case SC_SLEEP:
			*opt1 = 0;
			opt_flag = 1;
			break;

		case SC_POISON:
		case SC_CURSE:
		case SC_SILENCE:
		case SC_BLIND:
			*opt2 &= ~(1<<(type-SC_POISON));
			opt_flag = 1;
			break;

		case SC_SIGNUMCRUCIS:
			*opt2 &= ~0x40;
			opt_flag = 1;
			break;

		case SC_HIDING:
		case SC_CLOAKING:
			*option &= ~((type==SC_HIDING)?2:4);
			opt_flag = 1 ;
			break;

		case SC_SIGHT:
			*option &= ~1;
			opt_flag = 1;
			break;
		case SC_RUWACH:
			*option &= ~8192;
			opt_flag = 1;
			break;
		}

		if(opt_flag)	/* option�̕ύX��`���� */
			clif_changeoption(bl);

		if(bl->type==BL_PC && calc_flag)
			pc_calcstatus((struct map_session_data *)bl,0);	/* �X�e�[�^�X�Čv�Z */
	}

	return 0;
}
/*==========================================
 * �X�e�[�^�X�ُ�I���^�C�}�[
 *------------------------------------------
 */
int skill_status_change_timer(int tid, unsigned int tick, int id, int data)
{
	int type=data;
	struct block_list *bl;
	struct map_session_data *sd=NULL;
	struct status_change *sc_data;
	short *sc_count;

	bl=map_id2bl(id);
	if(bl==NULL)
		return 0;

	if(bl->type==BL_PC)
		sd=(struct map_session_data *)bl;

	sc_data=battle_get_sc_data(bl);
	sc_count=battle_get_sc_count(bl);

	if(sc_data == NULL) return 0;
	if(sc_data[type].timer != tid) {
		if(battle_config.error_log)
			printf("skill_status_change_timer %d != %d\n",tid,sc_data[type].timer);
	}

	switch(type){	/* ����ȏ����ɂȂ�ꍇ */
	case SC_MAXIMIZEPOWER:	/* �}�L�V�}�C�Y�p���[ */
	case SC_CLOAKING:		/* �N���[�L���O */
		if(sd){
			if( sd->status.sp > 0 ){	/* SP�؂��܂Ŏ��� */
				sd->status.sp--;
				clif_updatestatus(sd,SP_SP);
				sc_data[type].timer=add_timer(	/* �^�C�}�[�Đݒ� */
					sc_data[type].val2+tick, skill_status_change_timer,
					bl->id, data);
				return 0;
			}
		}
		break;

	case SC_HIDING:		/* �n�C�f�B���O */
		if(sd){		/* SP�������āA���Ԑ����̊Ԃ͎��� */
			if( sd->status.sp > 0 && (--sc_data[type].val2)>0 ){
				if(sc_data[type].val2 % (sc_data[type].val1+3) ==0 ){
					sd->status.sp--;
					clif_updatestatus(sd,SP_SP);
				}
				sc_data[type].timer=add_timer(	/* �^�C�}�[�Đݒ� */
					skill_get_time(TF_HIDING,sc_data[type].val1)+tick, skill_status_change_timer,
					bl->id, data);
				return 0;
			}
		}
		break;

	case SC_SIGHT:	/* �T�C�g */
	case SC_RUWACH:	/* ���A�t */
		{
			const int range=10;
			map_foreachinarea( skill_status_change_timer_sub,
				bl->m, bl->x-range, bl->y-range, bl->x+range,bl->y+range,0,
				bl,type,tick);

			if( (--sc_data[type].val2)>0 ){
				sc_data[type].timer=add_timer(	/* �^�C�}�[�Đݒ� */
					250+tick, skill_status_change_timer,
					bl->id, data);
				return 0;
			}
		}
		break;

	case SC_SIGNUMCRUCIS:		/* �V�O�i���N���V�X */
		{
			int race = battle_get_race(bl);
			if(race == 6 || battle_check_undead(race,battle_get_elem_type(bl))) {
				sc_data[type].timer=add_timer(1000*600+tick,skill_status_change_timer, bl->id, data );
				return 0;
			}
		}
		break;

	case SC_PROVOKE:	/* �v���{�b�N/�I�[�g�o�[�T�[�N */
		if(sc_data[type].val2!=0){	/* �I�[�g�o�[�T�[�N�i�P�b���Ƃ�HP�`�F�b�N�j */
			if(sd!=NULL && sd->status.hp>sd->status.max_hp>>2)	/* ��~ */
				break;
			sc_data[type].timer=add_timer( 1000+tick,skill_status_change_timer, bl->id, data );
			return 0;
		}
		break;

	case SC_WATERBALL:	/* �E�H�[�^�[�{�[�� */
		{
			struct block_list *target=map_id2bl(sc_data[type].val2);
			if(target==NULL || target->prev==NULL)
				break;
			skill_attack(BF_MAGIC,bl,bl,target,WZ_WATERBALL,sc_data[type].val1,tick,0);
			if((--sc_data[type].val3)>0) {
				sc_data[type].timer=add_timer( 150+tick,skill_status_change_timer, bl->id, data );
				return 0;
			}
		}
		break;

	case SC_DISSONANCE:	/* �s���a�� */
		if( (--sc_data[type].val2)>0){
			struct skill_unit *unit=
				(struct skill_unit *)sc_data[type].val4;
			struct block_list *src;

			if(!unit || !unit->group)
				break;
			src=map_id2bl(unit->group->src_id);
			if(!src)
				break;
			skill_attack(BF_MISC,src,&unit->bl,bl,unit->group->skill_id,sc_data[type].val1,tick,0);
			sc_data[type].timer=add_timer(skill_get_time2(unit->group->skill_id,unit->group->skill_lv)+tick,
				skill_status_change_timer, bl->id, data );
			return 0;
		}
		break;

	case SC_LULLABY:	/* �q��S */
		if( (--sc_data[type].val2)>0){
			struct skill_unit *unit=
				(struct skill_unit *)sc_data[type].val4;
			if(!unit || !unit->group || unit->group->src_id==bl->id)
				break;
			skill_additional_effect(bl,bl,unit->group->skill_id,sc_data[type].val1,BF_LONG|BF_SKILL|BF_MISC,tick);
			sc_data[type].timer=add_timer(skill_get_time(unit->group->skill_id,unit->group->skill_lv)/10+tick,
				skill_status_change_timer, bl->id, data );
			return 0;
		}
		break;

	case SC_STONE:
		if(sc_data[type].val2 != 0) {
			short *opt1 = battle_get_opt1(bl);
			sc_data[type].val2 = 0;
			sc_data[type].val4 = 0;
			battle_stopwalking(bl,1);
			if(opt1) {
				*opt1 = 1;
				clif_changeoption(bl);
			}
			sc_data[type].timer=add_timer(1000+tick,skill_status_change_timer, bl->id, data );
			return 0;
		}
		else if( (--sc_data[type].val3) > 0) {
			int hp = battle_get_max_hp(bl);
			if((++sc_data[type].val4)%5 == 0 && battle_get_hp(bl) > hp>>2) {
				hp = hp/100;
				if(hp < 1) hp = 1;
				if(bl->type == BL_PC)
					pc_heal((struct map_session_data *)bl,-hp,0);
				else if(bl->type == BL_MOB)
					((struct mob_data *)bl)->hp -= hp;
			}
			sc_data[type].timer=add_timer(1000+tick,skill_status_change_timer, bl->id, data );
			return 0;
		}
		break;
	case SC_POISON:
		if(sc_data[SC_SLOWPOISON].timer == -1) {
			if( (--sc_data[type].val3) > 0) {
				int hp = battle_get_max_hp(bl);
				if(battle_get_hp(bl) > hp>>2) {
					if(bl->type == BL_PC) {
						hp = 3 + hp*3/200;
						pc_heal((struct map_session_data *)bl,-hp,0);
					}
					else if(bl->type == BL_MOB) {
						hp = 3 + hp/200;
						((struct mob_data *)bl)->hp -= hp;
					}
				}
				sc_data[type].timer=add_timer(1000+tick,skill_status_change_timer, bl->id, data );
			}
		}
		else
			sc_data[type].timer=add_timer(1000+tick,skill_status_change_timer, bl->id, data );
		break;

	/* ���Ԑ؂ꖳ���H�H */
	case SC_AETERNA:
	case SC_TRICKDEAD:
	case SC_RIDING:
	case SC_FALCON:
	case SC_WEIGHT50:
	case SC_WEIGHT90:
		if(sc_data[type].timer==tid)
			sc_data[type].timer=add_timer( 1000*600+tick,skill_status_change_timer, bl->id, data );
		return 0;
	}

	return skill_status_change_end( bl,type,tid );
}

/*==========================================
 * �X�e�[�^�X�ُ�J�n
 *------------------------------------------
 */
int skill_encchant_eremental_end(struct block_list *bl,int type)
{
	struct status_change *sc_data=battle_get_sc_data(bl);

	if( type!=SC_ENCPOISON && sc_data[SC_ENCPOISON].timer!=-1 )	/* �G���`�����g�|�C�Y������ */
		skill_status_change_end(bl,SC_ENCPOISON,-1);
	if( type!=SC_ASPERSIO && sc_data[SC_ASPERSIO].timer!=-1 )	/* �A�X�y���V�I���� */
		skill_status_change_end(bl,SC_ASPERSIO,-1);
	if( type!=SC_FLAMELAUNCHER && sc_data[SC_FLAMELAUNCHER].timer!=-1 )	/* �t���C�������`������ */
		skill_status_change_end(bl,SC_FLAMELAUNCHER,-1);
	if( type!=SC_FROSTWEAPON && sc_data[SC_FROSTWEAPON].timer!=-1 )	/* �t���X�g�E�F�|������ */
		skill_status_change_end(bl,SC_FROSTWEAPON,-1);
	if( type!=SC_LIGHTNINGLOADER && sc_data[SC_LIGHTNINGLOADER].timer!=-1 )	/* ���C�g�j���O���[�_�[���� */
		skill_status_change_end(bl,SC_LIGHTNINGLOADER,-1);
	if( type!=SC_SEISMICWEAPON && sc_data[SC_SEISMICWEAPON].timer!=-1 )	/* �T�C�X�~�b�N�E�F�|������ */
		skill_status_change_end(bl,SC_SEISMICWEAPON,-1);

	return 0;
}
/*==========================================
 * �X�e�[�^�X�ُ�J�n
 *------------------------------------------
 */
int skill_status_change_start(struct block_list *bl,int type,int val1,int val2,int val3,int val4,int tick,int flag)
{
	struct map_session_data *sd = NULL;
	struct status_change* sc_data;
	short *sc_count, *option, *opt1, *opt2;
	int opt_flag = 0, calc_flag = 0,race, mode, elem, undead_flag;
	int scdef=0;

	if(bl->type == BL_SKILL)
		return 0;

	sc_data=battle_get_sc_data(bl);
	sc_count=battle_get_sc_count(bl);
	option=battle_get_option(bl);
	opt1=battle_get_opt1(bl);
	opt2=battle_get_opt2(bl);
	race=battle_get_race(bl);
	mode=battle_get_mode(bl);
	elem=battle_get_elem_type(bl);
	undead_flag=battle_check_undead(race,elem);

	if(sc_data == NULL || sc_count == NULL || option == NULL || opt1 == NULL || opt2 == NULL)
		return 0;

	if(type == SC_AETERNA && (sc_data[SC_STONE].timer != -1 || sc_data[SC_FREEZE].timer != -1) )
		return 0;

	switch(type){
		case SC_STONE:
		case SC_FREEZE:
			scdef=3+battle_get_mdef(bl)+battle_get_luk(bl)/3;
			break;
		case SC_STAN:
		case SC_SILENCE:
		case SC_POISON:
			scdef=3+battle_get_vit(bl)+battle_get_luk(bl)/3;
			break;
		case SC_SLEEP:
		case SC_BLIND:
			scdef=3+battle_get_int(bl)+battle_get_luk(bl)/3;
			break;
		case SC_CURSE:
			scdef=3+battle_get_luk(bl);
			break;

//		case SC_CONFUSION:
		default:
			scdef=0;
	}
	if(scdef>=100)
		return 0;
	if(bl->type==BL_PC){
		sd=(struct map_session_data *)bl;
		if(type == SC_ADRENALINE && !(skill_get_weapontype(BS_ADRENALINE)&(1<<sd->status.weapon)))
			return 0;

		if(SC_STONE<=type && type<=SC_BLIND){	/* �J�[�h�ɂ��ϐ� */
			if(sd->reseff[type-SC_STONE] > 0 && rand()%10000<sd->reseff[type-SC_STONE]){
				if(battle_config.battle_log)
					printf("PC %d skill_sc_start: card�ɂ��ُ�ϐ�����\n",sd->bl.id);
				return 0;
			}
		}
	}
	else if(bl->type == BL_MOB) {
	}
	else {
		if(battle_config.error_log)
			printf("skill_status_change_start: neither MOB nor PC !\n");
		return 0;
	}

	if(type==SC_FREEZE && undead_flag && !(flag&1))
		return 0;

	if((type == SC_ADRENALINE || type == SC_WEAPONPERFECTION || type == SC_OVERTHRUST) &&
		sc_data[type].timer != -1 && sc_data[type].val2 && !val2)
		return 0;

	if(mode & 0x20 && (type==SC_STONE || type==SC_FREEZE ||
		type==SC_STAN || type==SC_SLEEP || type==SC_SILENCE || type==SC_QUAGMIRE || type == SC_DECREASEAGI || type == SC_SIGNUMCRUCIS ||
		(type == SC_BLESSING && (undead_flag || race == 6))) && !(flag&1)){
		/* �{�X�ɂ͌����Ȃ�(�������J�[�h�ɂ����ʂ͓K�p�����) */
		return 0;
	}
	if(type==SC_FREEZE || type==SC_STAN || type==SC_SLEEP)
		battle_stopwalking(bl,1);

	if(sc_data[type].timer != -1){	/* ���łɓ����ُ�ɂȂ��Ă���ꍇ�^�C�}���� */
		if(sc_data[type].val1 > val1 && type != SC_COMBO && type != SC_DANCING && type != SC_DEVOTION &&
			type != SC_SPEEDPOTION0 && type != SC_SPEEDPOTION1 && type != SC_SPEEDPOTION2)
			return 0;
		if(type >=SC_STAN && type <= SC_BLIND)
			return 0;/* �p���������ł��Ȃ���Ԉُ�ł��鎞�͏�Ԉُ���s��Ȃ� */
		(*sc_count)--;
		delete_timer(sc_data[type].timer, skill_status_change_timer);
		sc_data[type].timer = -1;
	}

	switch(type){	/* �ُ�̎�ނ��Ƃ̏��� */
		case SC_PROVOKE:			/* �v���{�b�N */
			calc_flag = 1;
			if(tick <= 0) tick = 1000;	/* (�I�[�g�o�[�T�[�N) */
			break;
		case SC_ENDURE:				/* �C���f���A */
			if(tick <= 0) tick = 1000 * 60;
			break;
		case SC_CONCENTRATE:		/* �W���͌��� */
			calc_flag = 1;
			break;
		case SC_BLESSING:			/* �u���b�V���O */
			{
				if(bl->type == BL_PC || (!undead_flag && race != 6)) {
					if(sc_data[SC_CURSE].timer!=-1 )
						skill_status_change_end(bl,SC_CURSE,-1);
					if(sc_data[SC_STONE].timer!=-1 && sc_data[SC_STONE].val2 == 0)
						skill_status_change_end(bl,SC_STONE,-1);
				}
				calc_flag = 1;
			}
			break;
		case SC_ANGELUS:			/* �A���[���X */
			calc_flag = 1;
			break;
		case SC_INCREASEAGI:		/* ���x�㏸ */
			calc_flag = 1;
			if(sc_data[SC_DECREASEAGI].timer!=-1 )
				skill_status_change_end(bl,SC_DECREASEAGI,-1);
			break;
		case SC_DECREASEAGI:		/* ���x���� */
			calc_flag = 1;
			if(sc_data[SC_INCREASEAGI].timer!=-1 )
				skill_status_change_end(bl,SC_INCREASEAGI,-1);
			break;
		case SC_SIGNUMCRUCIS:		/* �V�O�i���N���V�X */
			calc_flag = 1;
			val2 = 14 + val1;
			tick = 600*1000;
			clif_emotion(bl,4);
			break;
		case SC_SLOWPOISON:
			if(sc_data[SC_POISON].timer == -1 )
				return 0;
			break;
		case SC_TWOHANDQUICKEN:		/* 2HQ */
			calc_flag = 1;
			break;
		case SC_ADRENALINE:			/* �A�h���i�������b�V�� */
			calc_flag = 1;
			break;
		case SC_WEAPONPERFECTION:	/* �E�F�|���p�[�t�F�N�V���� */
			if(battle_config.party_skill_penaly && !val2) tick /= 5;
			break;
		case SC_OVERTHRUST:			/* �I�[�o�[�X���X�g */
			if(battle_config.party_skill_penaly && !val2) tick /= 10;
			break;
		case SC_MAXIMIZEPOWER:		/* �}�L�V�}�C�Y�p���[(SP��1���鎞��,val2�ɂ�) */
			if(bl->type == BL_PC)
				val2 = tick;
			else
				tick = 5000*val1;
			break;
		case SC_ENCPOISON:			/* �G���`�����g�|�C�Y�� */
			calc_flag = 1;
			val2=(((val1 - 1) / 2) + 3)*100;	/* �ŕt�^�m�� */
			skill_encchant_eremental_end(bl,SC_ENCPOISON);
			break;
		case SC_POISONREACT:	/* �|�C�Y�����A�N�g */
			break;
		case SC_IMPOSITIO:			/* �C���|�V�e�B�I�}�k�X */
			calc_flag = 1;
			break;
		case SC_ASPERSIO:			/* �A�X�y���V�I */
			skill_encchant_eremental_end(bl,SC_ASPERSIO);
			break;
		case SC_SUFFRAGIUM:			/* �T�t���M�� */
		case SC_BENEDICTIO:			/* ���� */
		case SC_MAGNIFICAT:			/* �}�O�j�t�B�J�[�g */
		case SC_AETERNA:			/* �G�[�e���i */
		case SC_ENERGYCOAT:			/* �G�i�W�[�R�[�g */
			break;
		case SC_MAGICROD:
			val2 = val1*20;
			break;
		case SC_KYRIE:				/* �L���G�G���C�\�� */
			val2 = battle_get_max_hp(bl) * (val1 * 2 + 10) / 100;/* �ϋv�x */
			val3 = (val1 / 2 + 5);	/* �� */
			break;
		case SC_GLORIA:				/* �O�����A */
			calc_flag = 1;
			break;
		case SC_LOUD:				/* ���E�h�{�C�X */
			calc_flag = 1;
			break;
		case SC_TRICKDEAD:			/* ���񂾂ӂ� */
			break;
		case SC_QUAGMIRE:			/* �N�@�O�}�C�A */
			calc_flag = 1;
			if(sc_data[SC_CONCENTRATE].timer!=-1 )	/* �W���͌������ */
				skill_status_change_end(bl,SC_CONCENTRATE,-1);
			if(sc_data[SC_INCREASEAGI].timer!=-1 )	/* ���x�㏸���� */
				skill_status_change_end(bl,SC_INCREASEAGI,-1);
			if(sc_data[SC_TWOHANDQUICKEN].timer!=-1 )
				skill_status_change_end(bl,SC_TWOHANDQUICKEN,-1);
			if(sc_data[SC_SPEARSQUICKEN].timer!=-1 )
				skill_status_change_end(bl,SC_SPEARSQUICKEN,-1);
			if(sc_data[SC_ADRENALINE].timer!=-1 )
				skill_status_change_end(bl,SC_ADRENALINE,-1);
			if(sc_data[SC_LOUD].timer!=-1 )
				skill_status_change_end(bl,SC_LOUD,-1);
			break;
		case SC_FLAMELAUNCHER:		/* �t���[�������`���[ */
			skill_encchant_eremental_end(bl,SC_FLAMELAUNCHER);
			break;
		case SC_FROSTWEAPON:		/* �t���X�g�E�F�|�� */
			skill_encchant_eremental_end(bl,SC_FROSTWEAPON);
			break;
		case SC_LIGHTNINGLOADER:	/* ���C�g�j���O���[�_�[ */
			skill_encchant_eremental_end(bl,SC_LIGHTNINGLOADER);
			break;
		case SC_SEISMICWEAPON:		/* �T�C�Y�~�b�N�E�F�|�� */
			skill_encchant_eremental_end(bl,SC_SEISMICWEAPON);
			break;
		case SC_DEVOTION:			/* �f�B�{�[�V���� */
			calc_flag = 1;
			break;
		case SC_PROVIDENCE:			/* �v�����B�f���X */
			calc_flag = 1;
			val2=val1*5;
			break;
		case SC_REFLECTSHIELD:
			val2=10+val1*3;
			break;
		case SC_STRIPWEAPON:
		case SC_STRIPSHIELD:
		case SC_STRIPARMOR:
		case SC_STRIPHELM:
		case SC_CP_WEAPON:
		case SC_CP_SHIELD:
		case SC_CP_ARMOR:
		case SC_CP_HELM:
			break;

		case SC_AUTOSPELL:			/* �I�[�g�X�y�� */
			val4 = 5 + val1*2;
			break;

		case SC_VOLCANO:
			calc_flag = 1;
			val3 = val1*10;
			val4 = val1>=5?20: (val1==4?19: (val1==3?17: ( val1==2?14:10 ) ) );
			break;
		case SC_DELUGE:
			calc_flag = 1;
			val3 = val1>=5?15: (val1==4?14: (val1==3?12: ( val1==2?9:5 ) ) );
			val4 = val1>=5?20: (val1==4?19: (val1==3?17: ( val1==2?14:10 ) ) );
			break;
		case SC_VIOLENTGALE:
			calc_flag = 1;
			val3 = val1*3;
			val4 = val1>=5?20: (val1==4?19: (val1==3?17: ( val1==2?14:10 ) ) );
			break;

		case SC_SPEARSQUICKEN:		/* �X�s�A�N�C�b�P�� */
			calc_flag = 1;
			val2 = 20+val1;
			break;
		case SC_COMBO:
			break;
		case SC_BLADESTOP_WAIT:		/* ���n���(�҂�) */
			break;
		case SC_BLADESTOP:		/* ���n��� */
			if(val2==2) clif_bladestop((struct block_list *)val3,(struct block_list *)val4,1);
			break;

		case SC_LULLABY:			/* �q��S */
			val2 = 11;
			break;
		case SC_RICHMANKIM:
			break;
		case SC_ETERNALCHAOS:		/* �G�^�[�i���J�I�X */
			calc_flag = 1;
			break;
		case SC_DRUMBATTLE:			/* �푾�ۂ̋��� */
			calc_flag = 1;
			val2 = (val1+1)*25;
			val3 = (val1+1)*2;
			break;
		case SC_NIBELUNGEN:			/* �j�[�x�����O�̎w�� */
			calc_flag = 1;
			val2 = (val1+2)*50;
			break;
		case SC_ROKISWEIL:			/* ���L�̋��� */
			break;
		case SC_INTOABYSS:			/* �[���̒��� */
			break;
		case SC_SIEGFRIED:			/* �s���g�̃W�[�N�t���[�h */
			calc_flag = 1;
			val2 = 5 + val1*15;
			break;
		case SC_DISSONANCE:			/* �s���a�� */
			val2 = 10;
			break;
		case SC_WHISTLE:			/* ���J */
			calc_flag = 1;
			break;
		case SC_ASSNCROS:			/* �[�z�̃A�T�V���N���X */
			calc_flag = 1;
			break;
		case SC_POEMBRAGI:			/* �u���M�̎� */
			break;
		case SC_APPLEIDUN:			/* �C�h�D���̗ь� */
			calc_flag = 1;
			break;
		case SC_UGLYDANCE:			/* ��������ȃ_���X */
			val2 = 10;
			break;
		case SC_HUMMING:			/* �n�~���O */
			calc_flag = 1;
			break;
		case SC_DONTFORGETME:		/* ����Y��Ȃ��� */
			calc_flag = 1;
			if(sc_data[SC_INCREASEAGI].timer!=-1 )	/* ���x�㏸���� */
				skill_status_change_end(bl,SC_INCREASEAGI,-1);
			if(sc_data[SC_TWOHANDQUICKEN].timer!=-1 )
				skill_status_change_end(bl,SC_TWOHANDQUICKEN,-1);
			if(sc_data[SC_SPEARSQUICKEN].timer!=-1 )
				skill_status_change_end(bl,SC_SPEARSQUICKEN,-1);
			if(sc_data[SC_ADRENALINE].timer!=-1 )
				skill_status_change_end(bl,SC_ADRENALINE,-1);
			if(sc_data[SC_ASSNCROS].timer!=-1 )
				skill_status_change_end(bl,SC_ASSNCROS,-1);
			break;
		case SC_FORTUNE:			/* �K�^�̃L�X */
			calc_flag = 1;
			break;
		case SC_SERVICE4U:			/* �T�[�r�X�t�H�[���[ */
			calc_flag = 1;
			break;
		case SC_DANCING:			/* �_���X/���t�� */
			calc_flag = 1;
			break;

		case SC_EXPLOSIONSPIRITS:	// �����g��
			calc_flag = 1;
			val2 = 75 + 25*val1;
			break;
		case SC_STEELBODY:			// ����
			calc_flag = 1;
			break;
		case SC_AUTOCOUNTER:
			val3 = val4 = 0;
			break;

		case SC_SPEEDPOTION0:		/* �����|�[�V���� */
		case SC_SPEEDPOTION1:
		case SC_SPEEDPOTION2:
			calc_flag = 1;
			tick = 1000 * tick;
			val2 = 5*(2+type-SC_SPEEDPOTION0);
			break;

		/* option1 */
		case SC_STONE:				/* �Ή� */
			if(!(flag&2)) {
				int sc_def = battle_get_mdef(bl)*200;
				tick = tick - sc_def;
			}
			val3 = tick/1000;
			if(val3 < 1) val3 = 1;
			tick = 5000;
			val2 = 1;
			break;
		case SC_SLEEP:				/* ���� */
			if(!(flag&2)) {
//				int sc_def = 100 - (battle_get_int(bl) + battle_get_luk(bl)/3);
//				tick = tick * sc_def / 100;
//				if(tick < 1000) tick = 1000;
				tick = 30000;//�����̓X�e�[�^�X�ϐ��Ɋւ�炸30�b
			}
			break;
		case SC_FREEZE:				/* ���� */
			if(!(flag&2)) {
				int sc_def = 100 - battle_get_mdef(bl);
				tick = tick * sc_def / 100;
			}
			break;
		case SC_STAN:				/* �X�^���ival2�Ƀ~���b�Z�b�g�j */
			if(!(flag&2)) {
				int sc_def = 100 - (battle_get_vit(bl) + battle_get_luk(bl)/3);
				tick = tick * sc_def / 100;
			}
			break;

		/* option2 */
		case SC_POISON:				/* �� */
			calc_flag = 1;
			if(!(flag&2)) {
				int sc_def = 100 - (battle_get_vit(bl) + battle_get_luk(bl)/5);
				tick = tick * sc_def / 100;
			}
			val3 = tick/1000;
			if(val3 < 1) val3 = 1;
			tick = 1000;
			break;
		case SC_SILENCE:			/* ���فi���b�N�X�f�r�[�i�j */
			if(!(flag&2)) {
				int sc_def = 100 - battle_get_vit(bl);
				tick = tick * sc_def / 100;
			}
			break;
		case SC_BLIND:				/* �Í� */
			calc_flag = 1;
			if(!(flag&2)) {
				int sc_def = battle_get_lv(bl)/10 + battle_get_int(bl)/15;
				tick = 30000 - sc_def;
			}
			break;
		case SC_CURSE:
			calc_flag = 1;
			if(!(flag&2)) {
				int sc_def = 100 - battle_get_vit(bl);
				tick = tick * sc_def / 100;
			}
			break;

		/* option */
		case SC_HIDING:		/* �n�C�f�B���O */
			calc_flag = 1;
			if(bl->type == BL_PC) {
				val2 = tick / 1000;		/* �������� */
				tick = 1000;
			}
			break;
		case SC_CLOAKING:		/* �N���[�L���O */
			if(bl->type == BL_PC)
				val2 = tick;
			else
				tick = 5000*val1;
			break;
		case SC_SIGHT:			/* �T�C�g/���A�t */
		case SC_RUWACH:
			val2 = tick/250;
			tick = 10;
			break;

		/* �Z�[�t�e�B�E�H�[���A�j���[�} */
		case SC_SAFETYWALL:	case SC_PNEUMA:
			tick=((struct skill_unit *)val2)->group->limit;
			break;

		/* �A���N�� */
		case SC_ANKLE:
			break;

		/* �E�H�[�^�[�{�[�� */
		case SC_WATERBALL:
			tick=150;
			val3= (val1|1)*(val1|1)-1;
			break;

		/* �X�L������Ȃ�/���ԂɊ֌W���Ȃ� */
		case SC_RIDING:
			calc_flag = 1;
			tick = 600*1000;
			break;
		case SC_FALCON:	case SC_WEIGHT50:	case SC_WEIGHT90:
			tick=600*1000;
			break;

		case SC_AUTOGUARD:
			{
				int i,t;
				for(i=val2=0;i<val1;i++) {
					t = 5-(i>>1);
					val2 += (t < 0)? 1:t;
				}
			}
			break;

		case SC_DEFENDER:
			calc_flag = 1;
			val2 = 5 + val1*15;
			break;

		case SC_KEEPING:
		case SC_BARRIER:
		case SC_HALLUCINATION:
			break;

		default:
			if(battle_config.error_log)
				printf("UnknownStatusChange [%d]\n", type);
			return 0;
	}

	if(bl->type==BL_PC && type<SC_SENDMAX)
		clif_status_change(bl,type,1);	/* �A�C�R���\�� */

	/* option�̕ύX */
	switch(type){
		case SC_STONE:	case SC_FREEZE:	case SC_STAN:	case SC_SLEEP:
			battle_stopattack(bl);	/* �U����~ */
			skill_stop_dancing(bl);	/* ���t/�_���X�̒��f */
			{	/* �����Ɋ|����Ȃ��X�e�[�^�X�ُ������ */
				int i;
				for(i = SC_STONE; i <= SC_SLEEP; i++){
					if(sc_data[i].timer != -1){
						(*sc_count)--;
						delete_timer(sc_data[i].timer, skill_status_change_timer);
						sc_data[i].timer = -1;
					}
				}
			}
			if(type == SC_STONE)
				*opt1 = 6;
			else
				*opt1 = type - SC_STONE + 1;
			opt_flag = 1;
			break;
		case SC_POISON:	case SC_CURSE:	case SC_SILENCE:	case SC_BLIND:
			*opt2 |= 1<<(type-SC_POISON);
			opt_flag = 1;
			break;
		case SC_SIGNUMCRUCIS:
			*opt2 |= 0x40;
			opt_flag = 1;
			break;
		case SC_HIDING:	case SC_CLOAKING:
			battle_stopattack(bl);	/* �U����~ */
			*option |= ((type==SC_HIDING)?2:4);
			opt_flag =1 ;
			break;
		case SC_SIGHT:
			*option |= 1;
			opt_flag = 1;
			break;
		case SC_RUWACH:
			*option |= 8192;
			opt_flag = 1;
			break;
	}

	if(opt_flag)	/* option�̕ύX */
		clif_changeoption(bl);

	(*sc_count)++;	/* �X�e�[�^�X�ُ�̐� */

	sc_data[type].val1 = val1;
	sc_data[type].val2 = val2;
	sc_data[type].val3 = val3;
	sc_data[type].val4 = val4;
	/* �^�C�}�[�ݒ� */
	sc_data[type].timer = add_timer(
		gettick() + tick, skill_status_change_timer, bl->id, type);

	if(bl->type==BL_PC && calc_flag)
		pc_calcstatus(sd,0);	/* �X�e�[�^�X�Čv�Z */

	return 0;
}
/*==========================================
 * �X�e�[�^�X�ُ�S����
 *------------------------------------------
 */
int skill_status_change_clear(struct block_list *bl,int type)
{
	struct status_change* sc_data;
	short *sc_count, *option, *opt1, *opt2;
	int i;

	sc_data=battle_get_sc_data(bl);
	sc_count=battle_get_sc_count(bl);
	option=battle_get_option(bl);
	opt1=battle_get_opt1(bl);
	opt2=battle_get_opt2(bl);

	if(*sc_count == 0)
		return 0;
	for(i = 0; i < MAX_STATUSCHANGE; i++){
		if(sc_data[i].timer != -1){	/* �ُ킪����Ȃ�^�C�}�[���폜���� */
/*
			delete_timer(sc_data[i].timer, skill_status_change_timer);
			sc_data[i].timer = -1;

			if(!type && i<SC_SENDMAX)
				clif_status_change(bl,i,0);
*/

			skill_status_change_end(bl,i,-1);
		}
	}
	*sc_count = 0;
	*opt1 = 0;
	*opt2 = 0;
	*option &= OPTION_MASK;

	if(!type || type&2)
		clif_changeoption(bl);

	return 0;
}


/* �N���[�L���O�����i����Ɉړ��s�\�n�т����邩�j */
int skill_check_cloaking(struct block_list *bl)
{
	static int dx[]={-1, 0, 1,-1, 1,-1, 0, 1};
	static int dy[]={-1,-1,-1, 0, 0, 1, 1, 1};
	int end=1,i;
	if(bl->type == BL_PC && battle_config.pc_cloak_check_type&1)
		return 0;
	if(bl->type == BL_MOB && battle_config.monster_cloak_check_type&1)
		return 0;
	for(i=0;i<sizeof(dx)/sizeof(dx[0]);i++){
		int c=map_getcell(bl->m,bl->x+dx[i],bl->y+dy[i]);
		if(c==1 || c==5) end=0;
	}
	if(end){
		skill_status_change_end(bl, SC_CLOAKING, -1);
		*battle_get_option(bl)&=~4;	/* �O�̂��߂̏��� */
	}
	return end;
}



/*
 *----------------------------------------------------------------------------
 * �X�L�����j�b�g
 *----------------------------------------------------------------------------
 */

/* ���t/�_���X�X�L�����ǂ������� */
int skill_is_danceskill(int id)
{
	return ( (id>=BD_LULLABY && id<=BD_RAGNAROK) ||
		(id>=BA_DISSONANCE && id<=BA_APPLEIDUN && id!=BA_FROSTJOKE ) ||
		(id>=DC_UGLYDANCE && id<=DC_SERVICEFORYOU && id!=DC_SCREAM) );
}

/* ���t/�_���X����߂� */
void skill_stop_dancing(struct block_list *src)
{
	struct status_change* sc_data=battle_get_sc_data(src);
	if(sc_data && sc_data[SC_DANCING].timer==-1)
		return;
	skill_delunitgroup((struct skill_unit_group *)sc_data[SC_DANCING].val2);
	if(src->type==BL_PC)
		pc_calcstatus((struct map_session_data *)src,0);
}


/*==========================================
 * �X�L�����j�b�g������
 *------------------------------------------
 */
struct skill_unit *skill_initunit(struct skill_unit_group *group,int idx,int x,int y)
{
	struct skill_unit *unit=&group->unit[idx];

	if(!unit->alive)
		group->alive_count++;

	unit->bl.id=map_addobject(&unit->bl);
	unit->bl.type=BL_SKILL;
	unit->bl.m=group->map;
	unit->bl.x=x;
	unit->bl.y=y;
	unit->group=group;
	unit->val1=unit->val2=0;
	unit->alive=1;

	map_addblock(&unit->bl);
	clif_skill_setunit(unit);
	return unit;
}

int skill_unit_timer_sub_ondelete( struct block_list *bl, va_list ap );
/*==========================================
 * �X�L�����j�b�g�폜
 *------------------------------------------
 */
int skill_delunit(struct skill_unit *unit)
{
	struct skill_unit_group *group=unit->group;
	int range;

	if(!unit->alive || group==NULL)
		return 0;

	/* onlimit�C�x���g�Ăяo�� */
	skill_unit_onlimit( unit,gettick() );

	/* ondelete�C�x���g�Ăяo�� */
	range=unit->group->range;
	map_foreachinarea( skill_unit_timer_sub_ondelete, unit->bl.m,
		unit->bl.x-range,unit->bl.y-range,unit->bl.x+range,unit->bl.y+range,0,
		&unit->bl,gettick() );

	clif_skill_delunit(unit);

	unit->group=NULL;
	unit->alive=0;
	map_delobjectnofree(unit->bl.id);
	if(group->alive_count>0 && (--group->alive_count)<=0)
		skill_delunitgroup(group);

	return 0;
}
/*==========================================
 * �X�L�����j�b�g�O���[�v������
 *------------------------------------------
 */
static int skill_unit_group_newid=10;
struct skill_unit_group *skill_initunitgroup(struct block_list *src,
	int count,int skillid,int skilllv,int unit_id)
{
	int i;
	struct skill_unit_group *group=NULL, *list=NULL;
	int maxsug=0;

	if(src->type==BL_PC){
		list=((struct map_session_data *)src)->skillunit;
		maxsug=MAX_SKILLUNITGROUP;
	}else if(src->type==BL_MOB){
		list=((struct mob_data *)src)->skillunit;
		maxsug=MAX_MOBSKILLUNITGROUP;
	}
	if(list){
		for(i=0;i<maxsug;i++)	/* �󂢂Ă�����̌��� */
			if(list[i].group_id==0){
				group=&list[i];
				break;
			}

		if(group==NULL){	/* �󂢂ĂȂ��̂ŌÂ����̌��� */
			int j=0;
			unsigned maxdiff=0,x,tick=gettick();
			for(i=0;i<maxsug;i++)
				if((x=DIFF_TICK(tick,list[i].tick))>maxdiff){
					maxdiff=x;
					j=i;
				}
			skill_delunitgroup(&list[j]);
			group=&list[j];
		}
	}

	if(group==NULL){
		printf("skill_initunitgroup: error unit group !\n");
		exit(1);
	}

	group->src_id=src->id;
	group->party_id=battle_get_party_id(src);
	group->guild_id=battle_get_guild_id(src);
	group->group_id=skill_unit_group_newid++;
	if(skill_unit_group_newid<=0)
		skill_unit_group_newid=10;

	group->unit=calloc(sizeof(struct skill_unit)*count, 1);
	if(group->unit==NULL){
		printf("skill_initunitgroup: out of memory! \n");
		exit(1);
	}
	//memset(group->unit,0,sizeof(struct skill_unit)*count);

	group->unit_count=count;
	group->val1=group->val2=0;
	group->skill_id=skillid;
	group->skill_lv=skilllv;
	group->unit_id=unit_id;
	group->map=src->m;
	group->range=0;
	group->limit=10000;
	group->interval=1000;
	group->tick=gettick();
	group->valstr=NULL;

	if( skill_is_danceskill(skillid) )
		skill_status_change_start(src,SC_DANCING,skillid,(int)group,0,0,1000*181,0);

	return group;
}


/*==========================================
 * �X�L�����j�b�g�O���[�v�폜
 *------------------------------------------
 */
int skill_delunitgroup(struct skill_unit_group *group)
{
	struct block_list *src=map_id2bl(group->src_id);
	int i;
	if(group->unit_count<=0)
		return 0;

	if( skill_is_danceskill(group->skill_id) ){
		if(src)
			skill_status_change_end(src,SC_DANCING,-1);
	}

	group->alive_count=0;
	if(group->unit!=NULL){
		for(i=0;i<group->unit_count;i++)
			if(group->unit[i].alive)
				skill_delunit(&group->unit[i]);
	}
	if(group->valstr!=NULL){
		map_freeblock(group->valstr);
		group->valstr=NULL;
	}

	map_freeblock(group->unit);	/* free()�̑ւ�� */
	group->unit=NULL;
	group->src_id=0;
	group->group_id=0;
	group->unit_count=0;
	return 0;
}

/*==========================================
 * �X�L�����j�b�g�O���[�v�S�폜
 *------------------------------------------
 */
int skill_clear_unitgroup(struct block_list *src)
{
	struct skill_unit_group *group=NULL;
	int maxsug=0;
	if(src->type==BL_PC){
		group=((struct map_session_data *)src)->skillunit;
		maxsug=MAX_SKILLUNITGROUP;
	}else if(src->type==BL_MOB){
		group=((struct mob_data *)src)->skillunit;
		maxsug=MAX_MOBSKILLUNITGROUP;
	}
	if(group){
		int i;
		for(i=0;i<maxsug;i++)
			if(group[i].group_id>0)
				skill_delunitgroup(&group[i]);
	}
	return 0;
}


/*==========================================
 * �X�L�����j�b�g�O���[�v�̔�e��tick����
 *------------------------------------------
 */
struct skill_unit_group_tickset *skill_unitgrouptickset_search(
	struct block_list *bl,int group_id)
{
	int i,j=0,k,s=group_id%MAX_SKILLUNITGROUPTICKSET;
	struct skill_unit_group_tickset *set=NULL;
	if(bl->type==BL_PC){
		set=((struct map_session_data *)bl)->skillunittick;
	}else{
		set=((struct mob_data *)bl)->skillunittick;
	}
	if(set==NULL)
		return 0;
	for(i=0;i<MAX_SKILLUNITGROUPTICKSET;i++)
		if( set[(k=(i+s)%MAX_SKILLUNITGROUPTICKSET)].group_id == group_id )
			return &set[k];
		else if( set[k].group_id==0 )
			j=k;

	return &set[j];
}


/*==========================================
 * �X�L�����j�b�g�O���[�v�̔�e��tick�폜
 *------------------------------------------
 */
int skill_unitgrouptickset_delete(struct block_list *bl,int group_id)
{
	int i,s=group_id%MAX_SKILLUNITGROUPTICKSET;
	struct skill_unit_group_tickset *set=NULL,*ts;
	if(bl->type==BL_PC){
		set=((struct map_session_data *)bl)->skillunittick;
	}else{
		set=((struct mob_data *)bl)->skillunittick;
	}

	if(set!=NULL){

		for(i=0;i<MAX_SKILLUNITGROUPTICKSET;i++)
			if( (ts=&set[(i+s)%MAX_SKILLUNITGROUPTICKSET])->group_id == group_id )
				ts->group_id=0;

	}
	return 0;
}


/*==========================================
 * �X�L�����j�b�g�^�C�}�[���������p(foreachinarea)
 *------------------------------------------
 */
int skill_unit_timer_sub_onplace( struct block_list *bl, va_list ap )
{
	struct block_list *src;
	src=va_arg(ap,struct block_list*);
	unsigned int tick=va_arg(ap,unsigned int);

	if( ((struct skill_unit *)src)->alive) {
		if(battle_check_target(src,bl,((struct skill_unit *)src)->group->target_flag )>0)
			skill_unit_onplace( (struct skill_unit *)src, bl, tick );
	}
	return 0;
}


/*==========================================
 * �X�L�����j�b�g�^�C�}�[�폜�����p(foreachinarea)
 *------------------------------------------
 */
int skill_unit_timer_sub_ondelete( struct block_list *bl, va_list ap )
{
	struct block_list *src;
	unsigned int tick;
	src=va_arg(ap,struct block_list*);
	tick=va_arg(ap,unsigned int);

	if( ((struct skill_unit *)src)->alive &&
		battle_check_target(src,bl,((struct skill_unit *)src)->group->target_flag )>0 )
			skill_unit_ondelete( (struct skill_unit *)src, bl, tick );
	return 0;
}

/*==========================================
 * �X�L�����j�b�g�^�C�}�[�����p(foreachobject)
 *------------------------------------------
 */
int skill_unit_timer_sub( struct block_list *bl, va_list ap )
{
	struct skill_unit *unit=(struct skill_unit *)bl;
	struct skill_unit_group *group;
	int range;
	unsigned int tick;
	tick=va_arg(ap,unsigned int);

	if(!unit->alive)
		return 0;
	group=unit->group;
	range=(unit->range!=0)?unit->range:group->range;

	/* onplace�C�x���g�Ăяo�� */
	if(unit->alive && unit->range>=0){
		map_foreachinarea( skill_unit_timer_sub_onplace, bl->m,
			bl->x-range,bl->y-range,bl->x+range,bl->y+range,0,
			bl,tick);
		if(group->unit_id == 0xaa && DIFF_TICK(tick,group->tick)>=6000*group->val2){
			map_foreachinarea( skill_idun_heal, bl->m,
				bl->x-range,bl->y-range,bl->x+range,bl->y+range,0,unit);
			group->val2++;
		}
	}
	/* ���Ԑ؂�폜 */
	if(unit->alive &&
		(DIFF_TICK(tick,group->tick)>=group->limit || DIFF_TICK(tick,group->tick)>=unit->limit) ){
		struct block_list *ss = map_id2bl(group->src_id);
		if(ss && ss->type == BL_PC && (group->unit_id >= 0x8f && group->unit_id <= 0x98) && group->unit_id != 0x92) {
			if(group->unit_id != 0x91 || group->val2 == 0) {
				struct item item_tmp;
				memset(&item_tmp,0,sizeof(item_tmp));
				item_tmp.nameid=1065;
				item_tmp.identify=1;
				map_addflooritem(&item_tmp,1,bl->m,bl->x,bl->y,NULL,NULL,NULL,0);	// 㩕Ԋ�
			}
		}
		skill_delunit(unit);
	}
		
	if(group->unit_id == 0x8d) {
		unit->val1 -= 5;
		if(unit->val1 <= 0 && unit->limit + group->tick > tick + 700)
			unit->limit = DIFF_TICK(tick+700,group->tick);
	}

	return 0;
}
/*==========================================
 * �X�L�����j�b�g�^�C�}�[����
 *------------------------------------------
 */
int skill_unit_timer( int tid,unsigned int tick,int id,int data)
{
	map_freeblock_lock();

	map_foreachobject( skill_unit_timer_sub, BL_SKILL, tick );

	map_freeblock_unlock();

	return 0;
}

/*==========================================
 * �X�L�����j�b�g�ړ��������p(foreachinarea)
 *------------------------------------------
 */
int skill_unit_out_all_sub( struct block_list *bl, va_list ap )
{
	struct skill_unit *unit=(struct skill_unit *)bl;
	struct skill_unit_group *group;
	struct block_list *src;
	int range;
	unsigned int tick;
	src=va_arg(ap,struct block_list*);
	tick=va_arg(ap,unsigned int);

	if(!unit->alive || src->prev==NULL)
		return 0;

	group=unit->group;
	range=(unit->range!=0)?unit->range:group->range;

	if( range<0 || battle_check_target(bl,src,group->target_flag )<=0 )
		return 0;

	if( src->x >= bl->x-range && src->x <= bl->x+range &&
		src->y >= bl->y-range && src->y <= bl->y+range )
		skill_unit_onout( unit, src, tick );

	return 0;
}


/*==========================================
 * �X�L�����j�b�g�ړ�������
 *------------------------------------------
 */
int skill_unit_out_all( struct block_list *bl,unsigned int tick,int range)
{
	if(bl->prev==NULL)
		return 0;

	if(range<7)
		range=7;
	map_foreachinarea( skill_unit_out_all_sub,
		bl->m,bl->x-range,bl->y-range,bl->x+range,bl->y+range,BL_SKILL,
		bl,tick );

	return 0;
}

/*==========================================
 * �X�L�����j�b�g�ړ��������p(foreachinarea)
 *------------------------------------------
 */
int skill_unit_move_sub( struct block_list *bl, va_list ap )
{
	struct skill_unit *unit=(struct skill_unit *)bl;
	struct skill_unit_group *group;
	struct block_list *src;
	int range;
	unsigned int tick;
	src=va_arg(ap,struct block_list*);
	tick=va_arg(ap,unsigned int);

	if(!unit->alive || src->prev==NULL)
		return 0;

	group=unit->group;
	range=(unit->range!=0)?unit->range:group->range;

	if( range<0 || battle_check_target(bl,src,group->target_flag )<=0 )
		return 0;

	if( src->x >= bl->x-range && src->x <= bl->x+range &&
		src->y >= bl->y-range && src->y <= bl->y+range )
		skill_unit_onplace( unit, src, tick );
	else
		skill_unit_onout( unit, src, tick );

	return 0;
}


/*==========================================
 * �X�L�����j�b�g�ړ�������
 *------------------------------------------
 */
int skill_unit_move( struct block_list *bl,unsigned int tick,int range)
{
	if(bl->prev==NULL)
		return 0;

	if(range<7)
		range=7;
	map_foreachinarea( skill_unit_move_sub,
		bl->m,bl->x-range,bl->y-range,bl->x+range,bl->y+range,BL_SKILL,
		bl,tick );

	return 0;
}


/*----------------------------------------------------------------------------
 * �A�C�e������
 *----------------------------------------------------------------------------
 */

/*==========================================
 * �A�C�e�������\����
 *------------------------------------------
 */
int skill_can_produce_mix( struct map_session_data *sd, int nameid, int trigger )
{
	int i,j;

	if(nameid<=0)
		return 0;

	for(i=0;i<MAX_SKILL_PRODUCE_DB;i++){
		if(skill_produce_db[i].nameid == nameid )
			break;
	}
	if( i >= MAX_SKILL_PRODUCE_DB )	/* �f�[�^�x�[�X�ɂȂ� */
		return 0;

	if(trigger>=0){
		if(trigger==32 || trigger==16){
			if(skill_produce_db[i].itemlv!=trigger)	/* �t�@�[�}�V�[���|�[�V�����ނƗn�z�F���z�ΈȊO�͂��� */
				return 0;
		}else{
			if(skill_produce_db[i].itemlv>=16)		/* ����ȊO�͂��� */
				return 0;
			if( itemdb_wlv(nameid)>trigger )	/* ����Lv���� */
				return 0;
		}
	}
	if( (j=skill_produce_db[i].req_skill)>0 && pc_checkskill(sd,j)<=0 )
		return 0;		/* �X�L��������Ȃ� */

	for(j=0;j<5;j++){
		int id,x,y;
		if( (id=skill_produce_db[i].mat_id[j]) <= 0 )	/* ����ȏ�͍ޗ��v��Ȃ� */
			continue;
		if(skill_produce_db[i].mat_amount[j] <= 0) {
			if(pc_search_inventory(sd,id) < 0)
				return 0;
		}
		else {
			for(y=0,x=0;y<MAX_INVENTORY;y++)
				if( sd->status.inventory[y].nameid == id )
					x+=sd->status.inventory[y].amount;
			if(x<skill_produce_db[i].mat_amount[j])	/* �A�C�e��������Ȃ� */
				return 0;
		}
	}
	return i+1;
}


/*==========================================
 * �A�C�e�������\����
 *------------------------------------------
 */
int skill_produce_mix( struct map_session_data *sd,
	int nameid, int slot1, int slot2, int slot3 )
{
	int slot[3];
	int i,sc,ele,idx,equip,wlv,make_per,flag;

	if( !(idx=skill_can_produce_mix(sd,nameid,-1)) )	/* �����s�� */
		return 0;
	idx--;
	slot[0]=slot1;
	slot[1]=slot2;
	slot[2]=slot3;

	/* ���ߍ��ݏ��� */
	for(i=0,sc=0,ele=0;i<3;i++){
		int j;
		if( slot[i]<=0 )
			continue;
		j = pc_search_inventory(sd,slot[i]);
		if(j < 0)	/* �s���p�P�b�g(�A�C�e������)�`�F�b�N */
			continue;
		if(slot[i]==1000){	/* ���̂����� */
			pc_delitem(sd,j,1,1);
			sc++;
		}
		if(slot[i]>=994 && slot[i]<=997 && ele==0){	/* ������ */
			static const int ele_table[4]={3,1,4,2};
			pc_delitem(sd,j,1,1);
			ele=ele_table[slot[i]-994];
		}
	}

	/* �ޗ����� */
	for(i=0;i<5;i++){
		int j,id,x;
		if( (id=skill_produce_db[idx].mat_id[i]) <= 0 )
			continue;
		x=skill_produce_db[idx].mat_amount[i];	/* �K�v�Ȍ� */
		do{	/* �Q�ȏ�̃C���f�b�N�X�ɂ܂������Ă��邩������Ȃ� */
			int y=0;
			j = pc_search_inventory(sd,id);

			if(j >= 0){
				y = sd->status.inventory[j].amount;
				if(y>x)y=x;	/* ����Ă��� */
				pc_delitem(sd,j,y,0);
			}else {
				if(battle_config.error_log)
					printf("skill_produce_mix: material item error\n");
			}

			x-=y;	/* �܂�����Ȃ������v�Z */
		}while( j>=0 && x>0 );	/* �ޗ�������邩�A�G���[�ɂȂ�܂ŌJ��Ԃ� */
	}

	/* �m������ */
	equip = itemdb_isequip(nameid);
	if(!equip) {
		if(skill_produce_db[idx].req_skill==AM_PHARMACY) {
			if((nameid >= 501 && nameid <= 506) || (nameid >= 545 && nameid <= 547) || nameid == 525)
				make_per = 2000 + sd->status.base_level*30 + sd->paramc[3]*20 + sd->paramc[4]*15 + pc_checkskill(sd,AM_LEARNINGPOTION)*100 + pc_checkskill(sd,AM_PHARMACY)*300 + pc_checkskill(sd,AM_POTIONPITCHER)*100;
			else if(nameid == 970)
				make_per = 1500 + sd->status.base_level*30 + sd->paramc[3]*20 + sd->paramc[4]*15 + pc_checkskill(sd,AM_LEARNINGPOTION)*100 + pc_checkskill(sd,AM_PHARMACY)*300;
			else if(nameid == 7135)
				make_per = 1000 + sd->status.base_level*30 + sd->paramc[3]*20 + sd->paramc[4]*15 + pc_checkskill(sd,AM_LEARNINGPOTION)*100 + pc_checkskill(sd,AM_PHARMACY)*300 + pc_checkskill(sd,AM_DEMONSTRATION)*100;
			else if(nameid == 7136)
				make_per = 1000 + sd->status.base_level*30 + sd->paramc[3]*20 + sd->paramc[4]*15 + pc_checkskill(sd,AM_LEARNINGPOTION)*100 + pc_checkskill(sd,AM_PHARMACY)*300 + pc_checkskill(sd,AM_ACIDTERROR)*100;
			else if(nameid == 7137)
				make_per = 1000 + sd->status.base_level*30 + sd->paramc[3]*20 + sd->paramc[4]*15 + pc_checkskill(sd,AM_LEARNINGPOTION)*100 + pc_checkskill(sd,AM_PHARMACY)*300 + pc_checkskill(sd,AM_CANNIBALIZE)*100;
			else if(nameid == 7138)
				make_per = 1000 + sd->status.base_level*30 + sd->paramc[3]*20 + sd->paramc[4]*15 + pc_checkskill(sd,AM_LEARNINGPOTION)*100 + pc_checkskill(sd,AM_PHARMACY)*300 + pc_checkskill(sd,AM_SPHEREMINE)*100;
			else if(nameid == 7139)
				make_per = 1000 + sd->status.base_level*30 + sd->paramc[3]*20 + sd->paramc[4]*15 + pc_checkskill(sd,AM_LEARNINGPOTION)*100 + pc_checkskill(sd,AM_PHARMACY)*300 + pc_checkskill(sd,AM_CP_WEAPON)*100 +
					pc_checkskill(sd,AM_CP_SHIELD)*100 + pc_checkskill(sd,AM_CP_ARMOR)*100 + pc_checkskill(sd,AM_CP_HELM)*100;
			else
				make_per = 1000 + sd->status.base_level*30 + sd->paramc[3]*20 + sd->paramc[4]*15 + pc_checkskill(sd,AM_LEARNINGPOTION)*100 + pc_checkskill(sd,AM_PHARMACY)*300;
		}
		else {
			if(nameid == 998)
				make_per = 2000 + sd->status.base_level*30 + sd->paramc[4]*20 + sd->paramc[5]*10 + pc_checkskill(sd,skill_produce_db[idx].req_skill)*600;
			else if(nameid == 985)
				make_per = 1000 + sd->status.base_level*30 + sd->paramc[4]*20 + sd->paramc[5]*10 + (pc_checkskill(sd,skill_produce_db[idx].req_skill)-1)*500;
			else
				make_per = 1000 + sd->status.base_level*30 + sd->paramc[4]*20 + sd->paramc[5]*10 + pc_checkskill(sd,skill_produce_db[idx].req_skill)*500;
		}
	}
	else {
		int add_per;
		if(pc_search_inventory(sd,989) >= 0) add_per = 750;
		else if(pc_search_inventory(sd,988) >= 0) add_per = 500;
		else if(pc_search_inventory(sd,987) >= 0) add_per = 250;
		else if(pc_search_inventory(sd,986) >= 0) add_per = 0;
		else add_per = -500;
		if(ele) add_per -= 500;
		add_per -= sc*500;
		wlv = itemdb_wlv(nameid);
		make_per = ((250 + sd->status.base_level*15 + sd->paramc[4]*10 + sd->paramc[5]*5 + pc_checkskill(sd,skill_produce_db[idx].req_skill)*500 +
			add_per) * (100 - (wlv - 1)*20))/100 + pc_checkskill(sd,BS_WEAPONRESEARCH)*100 + ((wlv >= 3)? pc_checkskill(sd,BS_ORIDEOCON)*100 : 0);
	}

	if(make_per < 1) make_per = 1;

	if(skill_produce_db[idx].req_skill==AM_PHARMACY) {
		if( battle_config.pp_rate!=100 )
			make_per=make_per*battle_config.pp_rate/100;
	}
	else {
		if( battle_config.wp_rate!=100 )	/* �m���␳ */
			make_per=make_per*battle_config.wp_rate/100;
	}

//	if(battle_config.etc_log)
//		printf("make rate = %d\n",make_per);

	if(rand()%10000 < make_per){
		/* ���� */
		struct item tmp_item;
		memset(&tmp_item,0,sizeof(tmp_item));
		tmp_item.nameid=nameid;
		tmp_item.amount=1;
		tmp_item.identify=1;
		if(equip){	/* ����̏ꍇ */
			tmp_item.card[0]=0x00ff; /* ��������t���O */
			tmp_item.card[1]=((sc*5)<<8)+ele;	/* �����Ƃ悳 */
			*((unsigned long *)(&tmp_item.card[2]))=sd->char_id;	/* �L����ID */
		}
		else if((battle_config.produce_item_name_input && skill_produce_db[idx].req_skill!=AM_PHARMACY) ||
			(battle_config.produce_potion_name_input && skill_produce_db[idx].req_skill==AM_PHARMACY)) {
			tmp_item.card[0]=0x00fe;
			tmp_item.card[1]=0;
			*((unsigned long *)(&tmp_item.card[2]))=sd->char_id;	/* �L����ID */
		}

		if(skill_produce_db[idx].req_skill!=AM_PHARMACY) {	//���퐻���̏ꍇ
			clif_produceeffect(sd,0,nameid);/* ���퐻���G�t�F�N�g�p�P�b�g */
			clif_misceffect(&sd->bl,3); /* ���l�ɂ�������ʒm�i���B�����G�t�F�N�g�Ɠ����ł����́H�j */
		}
		else {	//�t�@�[�}�V�[�̏ꍇ
			clif_produceeffect(sd,2,nameid);/* ����G�t�F�N�g�p�P�b�g */
			clif_misceffect(&sd->bl,5); /* ���l�ɂ����s��ʒm*/
		}

		if((flag = pc_additem(sd,&tmp_item,1))) {
			clif_additem(sd,0,0,flag);
			map_addflooritem(&tmp_item,1,sd->bl.m,sd->bl.x,sd->bl.y,NULL,NULL,NULL,0);
		}
	}
	else {
		if(skill_produce_db[idx].req_skill!=AM_PHARMACY) {	//���퐻���̏ꍇ
			clif_produceeffect(sd,1,nameid);/* ���퐻�����s�G�t�F�N�g�p�P�b�g */
			clif_misceffect(&sd->bl,2); /* ���l�ɂ����s��ʒm */
		}
		else {	//�t�@�[�}�V�[�̏ꍇ
			clif_produceeffect(sd,3,nameid);/* ���򎸔s�G�t�F�N�g�p�P�b�g */
			clif_misceffect(&sd->bl,6); /* ���l�ɂ����s��ʒm*/
		}
	}
	return 0;
}

int skill_arrow_create( struct map_session_data *sd,int nameid)
{
	int i,j,flag,index=-1;
	struct item tmp_item;

	if(nameid <= 0)
		return 1;

	for(i=0;i<MAX_SKILL_ARROW_DB;i++)
		if(nameid == skill_arrow_db[i].nameid) {
			index = i;
			break;
		}

	if(index < 0 || (j = pc_search_inventory(sd,nameid)) < 0)
		return 1;

	pc_delitem(sd,j,1,0);
	for(i=0;i<5;i++) {
		memset(&tmp_item,0,sizeof(tmp_item));
		tmp_item.identify = 1;
		tmp_item.nameid = skill_arrow_db[index].cre_id[i];
		tmp_item.amount = skill_arrow_db[index].cre_amount[i];
		if(battle_config.making_arrow_name_input) {
			tmp_item.card[0]=0x00fe;
			tmp_item.card[1]=0;
			*((unsigned long *)(&tmp_item.card[2]))=sd->char_id;	/* �L����ID */
		}
		if(tmp_item.nameid <= 0 || tmp_item.amount <= 0)
			continue;
		if((flag = pc_additem(sd,&tmp_item,tmp_item.amount))) {
			clif_additem(sd,0,0,flag);
			map_addflooritem(&tmp_item,tmp_item.amount,sd->bl.m,sd->bl.x,sd->bl.y,NULL,NULL,NULL,0);
		}
	}

	return 0;
}

/*----------------------------------------------------------------------------
 * �������n
 */

/*==========================================
 * �X�L���֌W�t�@�C���ǂݍ���
 * skill_db.txt �X�L���f�[�^
 * cast_db.txt �X�L���̉r�����Ԃƃf�B���C�f�[�^
 * produce_db.txt �A�C�e���쐬�X�L���p�f�[�^
 * create_arrow_db.txt ��쐬�X�L���p�f�[�^
 * abra_db.txt �A�u���J�_�u�������X�L���f�[�^
 *------------------------------------------
 */
int skill_readdb(void)
{
	int i,j,k,l,m;
	FILE *fp;
	char line[1024],*p;
	char *filename[]={"db/produce_db.txt","db/produce_db2.txt"};

	/* �X�L���f�[�^�x�[�X */
	memset(skill_db,0,sizeof(skill_db));
	fp=fopen("db/skill_db.txt","r");
	if(fp==NULL){
		printf("can't read db/skill_db.txt\n");
		return 1;
	}
	while(fgets(line,1020,fp)){
		char *split[50], *split2[MAX_SKILL_LEVEL];
		if(line[0]=='/' && line[1]=='/')
			continue;
		for(j=0,p=line;j<14 && p;j++){
			split[j]=p;
			p=strchr(p,',');
			if(p) *p++=0;
		}
		if(split[13]==NULL || j<14)
			continue;

		i=atoi(split[0]);
		if(i<0 || i>MAX_SKILL_DB)
			continue;

/*		printf("skill id=%d\n",i); */
		memset(split2,0,sizeof(split2));
		for(j=0,p=split[1];j<MAX_SKILL_LEVEL && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<MAX_SKILL_LEVEL;k++)
			skill_db[i].range[k]=(split2[k])? atoi(split2[k]):atoi(split2[0]);
		skill_db[i].hit=atoi(split[2]);
		skill_db[i].inf=atoi(split[3]);
		skill_db[i].pl=atoi(split[4]);
		skill_db[i].nk=atoi(split[5]);
		skill_db[i].max=atoi(split[6]);

		memset(split2,0,sizeof(split2));
		for(j=0,p=split[7];j<MAX_SKILL_LEVEL && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<MAX_SKILL_LEVEL;k++)
			skill_db[i].num[k]=(split2[k])? atoi(split2[k]):atoi(split2[0]);

		if(strcmpi(split[8],"yes") == 0)
			skill_db[i].castcancel=1;
		else
			skill_db[i].castcancel=0;
		skill_db[i].cast_def_rate=atoi(split[9]);
		skill_db[i].inf2=atoi(split[10]);
		skill_db[i].maxcount=atoi(split[11]);
		if(strcmpi(split[12],"weapon") == 0)
			skill_db[i].skill_type=BF_WEAPON;
		else if(strcmpi(split[12],"magic") == 0)
			skill_db[i].skill_type=BF_MAGIC;
		else if(strcmpi(split[12],"misc") == 0)
			skill_db[i].skill_type=BF_MISC;
		else
			skill_db[i].skill_type=0;
		memset(split2,0,sizeof(split2));
		for(j=0,p=split[13];j<MAX_SKILL_LEVEL && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<MAX_SKILL_LEVEL;k++)
			skill_db[i].blewcount[k]=(split2[k])? atoi(split2[k]):atoi(split2[0]);
	}
	fclose(fp);
	printf("read db/skill_db.txt done\n");

	fp=fopen("db/skill_require_db.txt","r");
	if(fp==NULL){
		printf("can't read db/skill_require_db.txt\n");
		return 1;
	}
	while(fgets(line,1020,fp)){
		char *split[50], *split2[MAX_SKILL_LEVEL];
		if(line[0]=='/' && line[1]=='/')
			continue;
		for(j=0,p=line;j<29 && p;j++){
			split[j]=p;
			p=strchr(p,',');
			if(p) *p++=0;
		}
		if(split[28]==NULL || j<29)
			continue;

		i=atoi(split[0]);
		if(i<0 || i>MAX_SKILL_DB)
			continue;

		memset(split2,0,sizeof(split2));
		for(j=0,p=split[1];j<MAX_SKILL_LEVEL && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<MAX_SKILL_LEVEL;k++)
			skill_db[i].hp[k]=(split2[k])? atoi(split2[k]):atoi(split2[0]);

		memset(split2,0,sizeof(split2));
		for(j=0,p=split[2];j<MAX_SKILL_LEVEL && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<MAX_SKILL_LEVEL;k++)
			skill_db[i].sp[k]=(split2[k])? atoi(split2[k]):atoi(split2[0]);

		memset(split2,0,sizeof(split2));
		for(j=0,p=split[3];j<MAX_SKILL_LEVEL && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<MAX_SKILL_LEVEL;k++)
			skill_db[i].hp_rate[k]=(split2[k])? atoi(split2[k]):atoi(split2[0]);

		memset(split2,0,sizeof(split2));
		for(j=0,p=split[4];j<MAX_SKILL_LEVEL && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<MAX_SKILL_LEVEL;k++)
			skill_db[i].sp_rate[k]=(split2[k])? atoi(split2[k]):atoi(split2[0]);

		memset(split2,0,sizeof(split2));
		for(j=0,p=split[5];j<MAX_SKILL_LEVEL && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<MAX_SKILL_LEVEL;k++)
			skill_db[i].zeny[k]=(split2[k])? atoi(split2[k]):atoi(split2[0]);

		memset(split2,0,sizeof(split2));
		for(j=0,p=split[6];j<32 && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<32 && split2[k];k++) {
			l = atoi(split2[k]);
			if(l == 99) {
				skill_db[i].weapon = 0xffffffff;
				break;
			}
			else
				skill_db[i].weapon |= 1<<l;
		}

		if( strcmpi(split[7],"hiding")==0 ) skill_db[i].state=ST_HIDING;
		else if( strcmpi(split[7],"cloaking")==0 ) skill_db[i].state=ST_CLOAKING;
		else if( strcmpi(split[7],"hidden")==0 ) skill_db[i].state=ST_HIDDEN;
		else if( strcmpi(split[7],"riding")==0 ) skill_db[i].state=ST_RIDING;
		else if( strcmpi(split[7],"falcon")==0 ) skill_db[i].state=ST_FALCON;
		else if( strcmpi(split[7],"cart")==0 ) skill_db[i].state=ST_CART;
		else if( strcmpi(split[7],"shield")==0 ) skill_db[i].state=ST_SHIELD;
		else if( strcmpi(split[7],"sight")==0 ) skill_db[i].state=ST_SIGHT;
		else if( strcmpi(split[7],"explosionspirits")==0 ) skill_db[i].state=ST_EXPLOSIONSPIRITS;
		else if( strcmpi(split[7],"recover_weight_rate")==0 ) skill_db[i].state=ST_RECOV_WEIGHT_RATE;
		else if( strcmpi(split[7],"move_enable")==0 ) skill_db[i].state=ST_MOVE_ENABLE;
		else if( strcmpi(split[7],"water")==0 ) skill_db[i].state=ST_WATER;
		else skill_db[i].state=ST_NONE;

		memset(split2,0,sizeof(split2));
		for(j=0,p=split[8];j<MAX_SKILL_LEVEL && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<MAX_SKILL_LEVEL;k++)
			skill_db[i].spiritball[k]=(split2[k])? atoi(split2[k]):atoi(split2[0]);
		skill_db[i].itemid[0]=atoi(split[9]);
		skill_db[i].amount[0]=atoi(split[10]);
		skill_db[i].itemid[1]=atoi(split[11]);
		skill_db[i].amount[1]=atoi(split[12]);
		skill_db[i].itemid[2]=atoi(split[13]);
		skill_db[i].amount[2]=atoi(split[14]);
		skill_db[i].itemid[3]=atoi(split[15]);
		skill_db[i].amount[3]=atoi(split[16]);
		skill_db[i].itemid[4]=atoi(split[17]);
		skill_db[i].amount[4]=atoi(split[18]);
		skill_db[i].itemid[5]=atoi(split[19]);
		skill_db[i].amount[5]=atoi(split[20]);
		skill_db[i].itemid[6]=atoi(split[21]);
		skill_db[i].amount[6]=atoi(split[22]);
		skill_db[i].itemid[7]=atoi(split[23]);
		skill_db[i].amount[7]=atoi(split[24]);
		skill_db[i].itemid[8]=atoi(split[25]);
		skill_db[i].amount[8]=atoi(split[26]);
		skill_db[i].itemid[9]=atoi(split[27]);
		skill_db[i].amount[9]=atoi(split[28]);
	}
	fclose(fp);
	printf("read db/skill_require_db.txt done\n");

	/* �L���X�e�B���O�f�[�^�x�[�X */
	fp=fopen("db/cast_db.txt","r");
	if(fp==NULL){
		printf("can't read db/cast_db.txt\n");
		return 1;
	}
	while(fgets(line,1020,fp)){
		char *split[50], *split2[MAX_SKILL_LEVEL];
		if(line[0]=='/' && line[1]=='/')
			continue;
		for(j=0,p=line;j<5 && p;j++){
			split[j]=p;
			p=strchr(p,',');
			if(p) *p++=0;
		}
		if(split[4]==NULL || j<5)
			continue;

		i=atoi(split[0]);
		if(i<0 || i>MAX_SKILL_DB)
			continue;

		memset(split2,0,sizeof(split2));
		for(j=0,p=split[1];j<MAX_SKILL_LEVEL && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<MAX_SKILL_LEVEL;k++)
			skill_db[i].cast[k]=(split2[k])? atoi(split2[k]):atoi(split2[0]);

		memset(split2,0,sizeof(split2));
		for(j=0,p=split[2];j<MAX_SKILL_LEVEL && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<MAX_SKILL_LEVEL;k++)
			skill_db[i].delay[k]=(split2[k])? atoi(split2[k]):atoi(split2[0]);

		memset(split2,0,sizeof(split2));
		for(j=0,p=split[3];j<MAX_SKILL_LEVEL && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<MAX_SKILL_LEVEL;k++)
			skill_db[i].upkeep_time[k]=(split2[k])? atoi(split2[k]):atoi(split2[0]);

		memset(split2,0,sizeof(split2));
		for(j=0,p=split[4];j<MAX_SKILL_LEVEL && p;j++){
			split2[j]=p;
			p=strchr(p,':');
			if(p) *p++=0;
		}
		for(k=0;k<MAX_SKILL_LEVEL;k++)
			skill_db[i].upkeep_time2[k]=(split2[k])? atoi(split2[k]):atoi(split2[0]);
	}
	fclose(fp);
	printf("read db/cast_db.txt done\n");

	/* �����n�X�L���f�[�^�x�[�X */
	memset(skill_produce_db,0,sizeof(skill_produce_db));
	for(m=0;m<2;m++){
		fp=fopen(filename[m],"r");
		if(fp==NULL){
			if(m>0)
				continue;
			printf("can't read %s\n",filename[m]);
			return 1;
		}
		k=0;
		while(fgets(line,1020,fp)){
			char *split[16];
			int x,y;
			if(line[0]=='/' && line[1]=='/')
				continue;
			memset(split,0,sizeof(split));
			for(j=0,p=line;j<13 && p;j++){
				split[j]=p;
				p=strchr(p,',');
				if(p) *p++=0;
			}
			if(split[0]==NULL)
				continue;
			i=atoi(split[0]);
			if(i<=0)
				continue;

			skill_produce_db[k].nameid=i;
			skill_produce_db[k].itemlv=atoi(split[1]);
			skill_produce_db[k].req_skill=atoi(split[2]);

			for(x=3,y=0;split[x] && split[x+1] && y<5;x+=2,y++){
				skill_produce_db[k].mat_id[y]=atoi(split[x]);
				skill_produce_db[k].mat_amount[y]=atoi(split[x+1]);
			}
			k++;
			if(k >= MAX_SKILL_PRODUCE_DB)
				break;
		}
		fclose(fp);
		printf("read %s done (count=%d)\n",filename[m],k);
	}

	memset(skill_arrow_db,0,sizeof(skill_arrow_db));
	fp=fopen("db/create_arrow_db.txt","r");
	if(fp==NULL){
		printf("can't read db/create_arrow_db.txt\n");
		return 1;
	}
	k=0;
	while(fgets(line,1020,fp)){
		char *split[16];
		int x,y;
		if(line[0]=='/' && line[1]=='/')
			continue;
		memset(split,0,sizeof(split));
		for(j=0,p=line;j<13 && p;j++){
			split[j]=p;
			p=strchr(p,',');
			if(p) *p++=0;
		}
		if(split[0]==NULL)
			continue;
		i=atoi(split[0]);
		if(i<=0)
			continue;

		skill_arrow_db[k].nameid=i;

		for(x=1,y=0;split[x] && split[x+1] && y<5;x+=2,y++){
			skill_arrow_db[k].cre_id[y]=atoi(split[x]);
			skill_arrow_db[k].cre_amount[y]=atoi(split[x+1]);
		}
		k++;
		if(k >= MAX_SKILL_ARROW_DB)
			break;
	}
	fclose(fp);
	printf("read db/create_arrow_db.txt done (count=%d)\n",k);

	memset(skill_abra_db,0,sizeof(skill_abra_db));
	fp=fopen("db/abra_db.txt","r");
	if(fp==NULL){
		printf("can't read db/abra_db.txt\n");
		return 1;
	}
	k=0;
	while(fgets(line,1020,fp)){
		char *split[16];
		if(line[0]=='/' && line[1]=='/')
			continue;
		memset(split,0,sizeof(split));
		for(j=0,p=line;j<13 && p;j++){
			split[j]=p;
			p=strchr(p,',');
			if(p) *p++=0;
		}
		if(split[0]==NULL)
			continue;
		i=atoi(split[0]);
		if(i<=0)
			continue;

		skill_abra_db[i].req_lv=atoi(split[2]);
		skill_abra_db[i].per=atoi(split[3]);

		k++;
		if(k >= MAX_SKILL_ABRA_DB)
			break;
	}
	fclose(fp);
	printf("read db/abra_db.txt done (count=%d)\n",k);

	return 0;
}


/*==========================================
 * �X�L���֌W����������
 *------------------------------------------
 */
int do_init_skill(void)
{
	skill_readdb();

	add_timer_func_list(skill_unit_timer,"skill_unit_timer");
	add_timer_func_list(skill_castend_id,"skill_castend_id");
	add_timer_func_list(skill_castend_pos,"skill_castend_pos");
	add_timer_func_list(skill_timerskill,"skill_timerskill");
	add_timer_func_list(skill_status_change_timer,"skill_status_change_timer");
	add_timer_interval(gettick()+SKILLUNITTIMER_INVERVAL,skill_unit_timer,0,0,SKILLUNITTIMER_INVERVAL);

	return 0;
}