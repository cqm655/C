object freceptie: Tfreceptie
  Left = 0
  Top = 0
  Caption = 'freceptie'
  ClientHeight = 437
  ClientWidth = 771
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 32
    Width = 3
    Height = 13
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 771
    Height = 437
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'RECEPTIE'
      object Panel2: TPanel
        Left = 0
        Top = 57
        Width = 700
        Height = 312
        Color = clGradientInactiveCaption
        ParentBackground = False
        TabOrder = 0
        object Panel4: TPanel
          Left = 242
          Top = 0
          Width = 519
          Height = 313
          Caption = 'Panel4'
          TabOrder = 0
          object DBGrid1: TDBGrid
            Left = 1
            Top = 1
            Width = 517
            Height = 311
            Align = alClient
            DataSource = dm.dsqreceptie
            Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
            TabOrder = 0
            TitleFont.Charset = DEFAULT_CHARSET
            TitleFont.Color = clWindowText
            TitleFont.Height = -11
            TitleFont.Name = 'Tahoma'
            TitleFont.Style = []
            Columns = <
              item
                Expanded = False
                FieldName = 'RECEPTIE_ID'
                Title.Alignment = taCenter
                Title.Caption = 'Nr.'
                Width = 28
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'COD_PRODUS'
                Title.Alignment = taCenter
                Title.Caption = 'Cod Produs'
                Width = 100
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'PRODUS'
                Title.Alignment = taCenter
                Title.Caption = 'Produs'
                Width = 81
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'STOCK1'
                Title.Alignment = taCenter
                Title.Caption = 'Cant.'
                Width = 77
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'PRET_INTRARE'
                Title.Alignment = taCenter
                Title.Caption = 'Pret principal'
                Width = 80
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'PRET_VANZARE'
                Title.Alignment = taCenter
                Title.Caption = 'Pret vanzare'
                Width = 84
                Visible = True
              end>
          end
        end
      end
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 763
        Height = 57
        Align = alTop
        Color = clInactiveCaption
        ParentBackground = False
        TabOrder = 1
        object Label2: TLabel
          Left = 6
          Top = 8
          Width = 61
          Height = 13
          Caption = 'Nr. Factura'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label3: TLabel
          Left = 157
          Top = 8
          Width = 73
          Height = 13
          Caption = 'Data Factura'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label4: TLabel
          Left = 286
          Top = 8
          Width = 44
          Height = 13
          Caption = 'Emitent'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Edit1: TEdit
          Left = 8
          Top = 27
          Width = 112
          Height = 21
          TabOrder = 0
        end
        object Edit3: TEdit
          Left = 286
          Top = 26
          Width = 388
          Height = 21
          TabOrder = 1
        end
        object Button1: TButton
          Left = 680
          Top = 27
          Width = 75
          Height = 25
          Caption = 'EXECUTA'
          TabOrder = 2
          OnClick = Button1Click
        end
        object DateTimePicker1: TDateTimePicker
          Left = 157
          Top = 26
          Width = 100
          Height = 25
          Date = 44371.000000000000000000
          Time = 0.804150289346580400
          TabOrder = 3
        end
      end
      object Panel13: TPanel
        Left = 0
        Top = 57
        Width = 241
        Height = 312
        Enabled = False
        TabOrder = 2
        object Label5: TLabel
          Left = 8
          Top = 6
          Width = 39
          Height = 13
          Caption = 'Produs'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label6: TLabel
          Left = 8
          Top = 54
          Width = 105
          Height = 13
          Caption = 'Unitate de masura'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label9: TLabel
          Left = 6
          Top = 104
          Width = 25
          Height = 13
          Caption = 'Stoc'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label10: TLabel
          Left = 125
          Top = 104
          Width = 94
          Height = 13
          Caption = 'Data Valabilitate'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label7: TLabel
          Left = 6
          Top = 154
          Width = 68
          Height = 13
          Caption = 'Pret Intrare'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label8: TLabel
          Left = 125
          Top = 154
          Width = 60
          Height = 13
          Caption = 'Pret Iesire'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Edit2: TEdit
          Left = 6
          Top = 25
          Width = 198
          Height = 21
          ReadOnly = True
          TabOrder = 0
        end
        object Button2: TButton
          Left = 210
          Top = 23
          Width = 26
          Height = 25
          Caption = '...'
          TabOrder = 1
          OnClick = Button2Click
        end
        object Edit4: TEdit
          Left = 6
          Top = 73
          Width = 198
          Height = 21
          ReadOnly = True
          TabOrder = 2
        end
        object Button3: TButton
          Left = 210
          Top = 71
          Width = 26
          Height = 25
          Caption = '...'
          TabOrder = 3
          OnClick = Button3Click
        end
        object Edit7: TEdit
          Left = 6
          Top = 123
          Width = 92
          Height = 21
          TabOrder = 4
        end
        object DateTimePicker2: TDateTimePicker
          Left = 125
          Top = 123
          Width = 111
          Height = 25
          Date = 44371.000000000000000000
          Time = 0.810454409722297000
          TabOrder = 5
        end
        object Edit5: TEdit
          Left = 7
          Top = 173
          Width = 91
          Height = 21
          TabOrder = 6
        end
        object Edit6: TEdit
          Left = 124
          Top = 173
          Width = 95
          Height = 21
          TabOrder = 7
        end
        object Button6: TButton
          Left = 6
          Top = 225
          Width = 91
          Height = 34
          Caption = 'EXECUTA'
          TabOrder = 8
          OnClick = Button6Click
        end
        object Button5: TButton
          Left = 141
          Top = 226
          Width = 95
          Height = 34
          Caption = 'Anuleaza'
          TabOrder = 9
        end
        object Button4: TButton
          Left = 7
          Top = 265
          Width = 230
          Height = 47
          Caption = 'Urmatoare Factura'
          TabOrder = 10
          OnClick = Button4Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'PRODUSE'
      ImageIndex = 1
      object Panel5: TPanel
        Left = -4
        Top = -6
        Width = 333
        Height = 479
        Color = clMenu
        ParentBackground = False
        TabOrder = 0
        object PageControl2: TPageControl
          Left = 1
          Top = 1
          Width = 331
          Height = 477
          ActivePage = TabSheet6
          Align = alClient
          TabOrder = 0
          object TabSheet6: TTabSheet
            Caption = 'Main'
            object Panel10: TPanel
              Left = 0
              Top = 0
              Width = 323
              Height = 449
              Align = alClient
              TabOrder = 0
              object Panel11: TPanel
                Left = 0
                Top = 8
                Width = 321
                Height = 97
                Alignment = taLeftJustify
                BiDiMode = bdLeftToRight
                BorderWidth = 1
                BorderStyle = bsSingle
                Caption = 'Cautare Rapida'
                DoubleBuffered = False
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentBiDiMode = False
                ParentDoubleBuffered = False
                ParentFont = False
                TabOrder = 0
                VerticalAlignment = taAlignTop
                object rb1: TRadioButton
                  Left = 16
                  Top = 24
                  Width = 113
                  Height = 17
                  Caption = 'Dupa Denumire'
                  TabOrder = 0
                  OnClick = rb1Click
                end
                object rb2: TRadioButton
                  Left = 184
                  Top = 24
                  Width = 113
                  Height = 17
                  Caption = 'Dupa Cod'
                  TabOrder = 1
                  OnClick = rb1Click
                end
                object ecautare: TEdit
                  Left = 16
                  Top = 47
                  Width = 241
                  Height = 24
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -13
                  Font.Name = 'Tahoma'
                  Font.Style = [fsBold]
                  ParentFont = False
                  TabOrder = 2
                  TextHint = 'Cautare dupa denumire'
                  OnChange = ecautareChange
                end
              end
              object Button8: TButton
                Left = 48
                Top = 111
                Width = 225
                Height = 58
                Caption = 'SELECTEAZA'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -19
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                TabOrder = 1
                OnClick = Button8Click
              end
              object Button9: TButton
                Left = 48
                Top = 175
                Width = 225
                Height = 58
                Caption = 'ANULEAZA'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -19
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                TabOrder = 2
              end
              object Button10: TButton
                Left = 48
                Top = 263
                Width = 225
                Height = 58
                Caption = 'Inregistreaza'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -19
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 3
              end
              object Button11: TButton
                Left = 48
                Top = 327
                Width = 225
                Height = 58
                Caption = 'Modifica'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -19
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 4
              end
              object Button12: TButton
                Left = 48
                Top = 391
                Width = 225
                Height = 58
                Caption = 'Elimina'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -19
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
                TabOrder = 5
              end
            end
          end
          object TabSheet7: TTabSheet
            Caption = 'Inregistrare'
            ImageIndex = 1
            object Panel12: TPanel
              Left = 0
              Top = 0
              Width = 323
              Height = 449
              Align = alClient
              TabOrder = 0
              object Label13: TLabel
                Left = 13
                Top = 22
                Width = 107
                Height = 13
                Caption = 'DENUMIRE PRODUS'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
              end
              object Label14: TLabel
                Left = 13
                Top = 78
                Width = 72
                Height = 13
                Caption = 'COD PRODUS'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
              end
              object Edit11: TEdit
                Left = 11
                Top = 41
                Width = 233
                Height = 21
                TabOrder = 0
              end
              object Edit12: TEdit
                Left = 11
                Top = 97
                Width = 231
                Height = 21
                TabOrder = 1
              end
              object Button17: TButton
                Left = 63
                Top = 140
                Width = 201
                Height = 59
                Caption = 'INREGISTREAZA'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -19
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                TabOrder = 2
                OnClick = Button17Click
              end
              object Button18: TButton
                Left = 63
                Top = 220
                Width = 201
                Height = 59
                Caption = 'ANULEAZA'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -19
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
                TabOrder = 3
                OnClick = Button18Click
              end
            end
          end
          object TabSheet8: TTabSheet
            Caption = 'Editare'
            ImageIndex = 2
            object Label15: TLabel
              Left = 11
              Top = 8
              Width = 97
              Height = 13
              Caption = 'Denumire Produs'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object Label16: TLabel
              Left = 11
              Top = 64
              Width = 72
              Height = 13
              Caption = 'COD PRODUS'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object Image1: TImage
              Left = 254
              Top = 212
              Width = 50
              Height = 50
              Picture.Data = {
                0954506E67496D61676589504E470D0A1A0A0000000D49484452000000320000
                003208060000001E3F88B1000000097048597300000EC400000EC401952B0E1B
                00000FFE4944415478DABD5A097454559AFEDFABF76A79B56523C410201B04D2
                104220C1038281E9014CA3F6A888D27DE4A09CC171743848238EADDDD3C3D8B6
                7BAB6D77EBC18519451A97A3330CE2D210A0B121614908BBD90C31842424A9D4
                FEEA2DF3BFB55E55BD4AB07B66EE49A5AADE72EFFFDDEFFB977B5F11106F24BE
                04F8FF69C6B1FE57C6254C3ABFD68EBFAB0164D2773320C97D8E3586D6A740C0
                D8EDFF82A9BFB6CF94FBAF1588B125CF189C984F0341929463DC04BB75421113
                F38F4C12D97021F0422E08824BB9920CE0AB8FB0393A69B7A78BEDEE0885FBBE
                8D88A2C055FD3926248D23248D3DDA77612C20C69B4C3B383C8FA61C564B96A7
                64DA543AAFB0D6C2B81750DEAC4AEBB8097954D638205D5E20AC0EF90604067C
                C007FC603FB0FDDFF672C3834D7CD87F38D6DB593FD276FE6298E507171C8D71
                A3D830AA8D84D1B06BA052BFEE782D93E3CE9FB4DC5956799335BF703E9D3BB1
                90CA1A0F046D45ABD5BBC47807A23A6D84FA2EC658E006AF40ACEF5227DBD3F9
                55F0C2C94FFD3D97F6CEA90F0D8C366E1A5B4933464675FA8FAA812C646C73B3
                6655FFD43567C97C6B6E4116C9784894966CADA8FC4B4290CA3DA12242698110
                F4096C7FF760E0F8FEAF069B1A9FEC0C478FDDD69862F8A860C6F2115DB70DB5
                76B0B95C058EEC9CFBDCD367DFEFAC58984B58EDAA3106834531890D3175386D
                5482881F22700AD808044F1DEAF39F3DF9FBF0E0C01B6C20D05D5D1FD16E3682
                4991BA59F84D00A01D6BAAF3947B0B4B7EEE2AAFFEA17552B995B0D071BBC524
                008280D2E140E479F9B3D2230984C582D2A3E4CF3A204D6BA4F251E463C0769D
                6503671A3FF675B6FDA2F2D391B3A3A846B7351D230974362D656678264F7CCA
                5DB5B88ECE9D8C32A274E335FB258385680C3F5881CCCC032A230708871B48AB
                4D39CD46410CFB811BEE0761E80A1E6181B4D12A2B842235423547E480EDFB46
                F09FD8BFC7F7CDA57F9EFD794803934EF23223A40910F9C23F2DB1934E3B35CD
                9397F3B4A772D1726A7C1145889A94E20C889C08842D1BAC53ABC03AB10401B8
                64A7272C86D99758E239D9C9C57000D84B6DC05E3C0162F42A5E671487024A40
                DFE1063A39FFC9837B477AFBB784A2FCF905FB2290C6D6042029681BEB9C9332
                C6653CEF9956751B9D3F15B5412A00048D0D0B90CE5CB0965D0FF6193540529A
                DC101831768A12B818444E37007BE1083A7C1FDEC32B1A216D602DB91E629D5F
                21E033C2C8B9131F0DF50F6FAAF934D89D3CD95A4B3BDA23A540ADA9CAFA7946
                71E923F6A20A2B41D9151204252A89220D7471353866DD0854CE75AA3CAE25BF
                2636519066FE32849B0F40ACBD11D92171626E0066CEDF82EFC3AD20860621D2
                D1CC0EB7B53DF3F6C9C15F3CDB069C593F69C3EFE1A58EF90545E33E61A655E7
                908E0CD5780584C011E0A8BA051CB31783C5E9BE3683C760890FFA11CC41945E
                049CD54B8164DC30F4E63FE1F71008A161089D6F1CE8EEE8BF75C117E12326D2
                3207B27B31933B258F7EC35B36A38E1A571C8F4AD21F61035BE50FC039AF0E48
                DA9660A00C946371E011E0877A81BFDA839219563A756680253B1F2C180830EF
                005056F93E51F535F933FA9034064151F2B1C1D7D72390B06C25D7D70EBE0BA7
                F77C7D257ADF8AFD91BE31A5F5CB0A1B7553B1F59EEC7CEFD3CCD47939187640
                4E73F280343A742D3817AE44263C89338E6193EBEB02B6ED3844CF1F91416019
                95308888D18E4230B669D7A30FCC012A77126861DC8CBDC1DFDF87D12EA44C14
                CF42E8E2D18181CBBE2D7BDAD97F7FFC54941B0D08B9778933AFF03AFA456F51
                C91DF4B8225291948C05C8EC52702F7F00B01C4902C1A3D3EE87F089CF81EFEB
                C0E9E340CDF1293A16A5A884336EC92D44692E03FBCCC5727E316B577FBB0693
                64480DCD80E54C8780B9E583F6CBB18D75FB82BD69817CCF4B92DB6A9DB5E373
                9DDB9DC5E505A4DD13CF17040DCC8DEB81A95C2255BAFAAC497288347F01C1FA
                FF90C32AD2A02773D1C438198C9A33089B1B3C2B7F06B6C9D3CC81BCF2230412
                54F20B7AAE101E8160C7D9EE2B7DC135EBEA83F5677C821E69138AC69D8B187B
                591EFDC4F849B98F51E38BD1605A0742E44C87CC1F3D89B349C77D02E51469D9
                07C13FBE817EE1978A15C5F80404698A2D9A415FBB193CCBEEC1711219D126E9
                EACBAB30CF04E52C21831750BEBDED70E552DF2F2F5C8E6DBDEB50484B2C8945
                E3CE25CE9C99F9B6F7B30B0B6A2DDEEB94C1656911C0D43E00CE9A1509837197
                BF06FFDE9781EFB9180F06C945A3018E3E18ED021B463DD7C23B527DCD103C06
                7E7D3B000211B59A0CEB31C17719AE765CAA6FE96157DEB53F3890CC88DC5056
                C5B525CC51D7C4493916264B0FB760CF848CBB9F41DF288C0F188B42F0AB9D10
                3EFC2E66F6581201E660645E305AD9E6AE02E70D0802D72BA3B581176F5518D1
                A4886F7C78180297BA06EA5B83F3D61D08B69BF908F9C152E7F7E74D717F86A5
                39EAD7A5CF3255783D786E7914672F43BF981FEE85E1F7B680D0DF1EAFB7C424
                EB351A12D425F9865359B700915A098BA0D75D52FE90A3AC5687493EC94580ED
                BD04472F0E2FBBE3F3E097609247C83D37B9FE7E5699E77714C67A8276E8543B
                E6AE0667EDBD18891DFAC5D1D60618D9B90911718ABD0610A21928E3D4896A91
                282A8E2F070DC2608E760C408F58CA6729EFF0C061686F3E37F80F759F065E37
                0342ED5BE179745A997BABC5330EA492449B6566F143C0CC5BA514816A0B1DDD
                05C1BDCFA530216B1C927CC2489056E0AA6044881F94BFAB124A64CBC01ADEC1
                A11ACE9F1B7C62C96EFFAFF0009702E4D00F3D4F96943A1F211969ADED04AD4B
                D74D8F817DF6ADD84FBC500E7CF932840EBCA6D45E6AB2893391DE47E232527B
                D7A65C8A3B995381CC9991085EAA13AF9E4680AAE6A415A5BF1F5ACFFB9E59F8
                C9C84F4D811C4420A5A5F647A421A49028AA46D185355818161B7A1721D67512
                B89E33FA541B5D4107625600E9C789F8694209DCCC9287C173F363F11C854687
                8FEE80910F372BC0A5302D011178686D0D3FB3E8E35420D254937B6FF63C5151
                66FF1981B34368A1D4607C8A54128EC559200C3627109184479394769D6BC553
                E0AA5D17BF06F354F0D03608ECF91715AF72BD802A68B910FED765FFE5DF6A0A
                E40FCBDC0F2E9CC9BC4852C611154A538C4EB294480E5146464CD811554644FD
                A4053C6B7782BD6C915E4C4A0563F08BE72074E855D07C46BA4F8C8970E87468
                E3AACFFCBF319316F9C222E76DABE63ADFB7D8D405348806D3482CA13252A75A
                0B34FA8A310A141D04955245D6A6324B3C40649641E6BDEF02953551979610BC
                8AB2DA08ECF9CF1318E42302FCE15870E5C307831F81216AE91EBC7E96BDF227
                0B5CFBDD99B44732241E3D4490EAAE9CC72E245B93908985D010441ADEC0197C
                05E37D14466B84418D521D679FBF015C8BFF3121C4737D1761F8ED55E8DCBD71
                BE31DAF9876223CF1D0E2C7EAD39D20466EB917BCBED85F7CF737E38B9C05A95
                1CFA64208F9E4F0F02336EA4611B841BDE043132089A332B92547DC1C479A4B3
                644E05FAC7AF70BD3F2B61F1153AF62E04FF7B8BECF4FA7DF8EAEA664FFCAE21
                78FB9B67229DA6FCDE524867ADAF713E3D678A639DBC5142286CC8401C5EC8D9
                7CCE7476458C22E1C3BF8648E3360431AC779DB0BB08AABB415210B1648263D1
                E3C054DF21972F5A137081E6DBB11AB8CE3FEB376BFE71FCEBC8B6D71B825B3E
                E96487CDA4255871B9FCFC12F79DCB67322F79332C59FA1929CCDBBD90BD2971
                8B496384FDA609FC1FDC835A40264851C39EB629952CFEB378C1366F3338E7FF
                18EF532A60D9D1B13A8F9EFD18A3D56679E96BDC82F50DF1837B5B421B36EDF3
                EF620560D533291B74B07EA6BD62CD3CD78B2505D65A92D2AA4EFC4369656F3C
                9BB2F696730D32126ADC05D153EF80E83B8715402C9EDDF5CDDE380F228F4B01
                EF74B055FC1899B85306615CF6F2836D58356C815877839A70D5B28F13A1AD9B
                ADDF7E24B0F1B596C829302C77535688054E32E3A9BF716F58349379D8E1245D
                5A01473ADC90F9D099B41B08224A21D6730EA217BF84D885DDE8A0EDB8A6E731
                CDAAD7A31142CC02A4A718E8B215609BF27DA0F3A7232B74429F427808C2475E
                8668F33B321BC69DCC5040081C6A09BDF0E81FFD2F750785E16420C9FB5AE42D
                C5D6AAC7977A5E299C6CAB212C8AAB12E823590F9E566734A6665A2A65F3411A
                5C080CE09ABD03B82BADC0FBAE28AEE01D0FD4F852B0641701E9CAC1A2D49E70
                1FA156B691A6B7D1D75E455FF3A1C444DDC1A5CF1D9DD1867FFB62E4A1FF6C63
                4F1840E81B74C94D02E3FAC95CC75D0F2EF73EEFF4522E4266C403990F9C0601
                9D39DAF20E1AC28075DADFA1EF64261833AA6F24814E602232847EB10B22475F
                50FC42DF3F13E5D573D0C7075EFD6C78D3B38DE19D787900AE71838E62282878
                EBF68CA71755386FA3ED0425452DEFDA3FA11FBC8DAFB7E468669DB6126CE5AB
                81CC280265AB73EC0DBA541FC3DAC9D701D1333B30F1BD2F33A130A0C8497A8F
                4504EE6073F0A3B51F0E6F097120ED367290B42B3ADAC8D63BCB6D4B1E58E4DE
                5A5E629F6B61185C97DC2F0311599FB27B8E6B164BEE4CB04D5F0D74511D1EA3
                4DC1C48BC0A43D305C83C73AF640F4DC0EE0FB5BE4A75AFA1E9AA080E131349D
                6D8F1EFBED819127769D8DEE0388472A3320C9CF1DE4E6A209D7DD33ED2BD62E
                746F2E9D6CABA0EC18A0C598AC48B9A227D477D4BB25B712ACC5B7E2FB5C8C70
                59981330434BC98850371644E911032EC2B8B09C30F9BE63C0B67F82EF989CD1
                37740678501F4DE0BA831585B6AEE8A9370FFA9F7DAF25B23B10135324752D8C
                68A0B2D6CD76ACB8F746F7862985B64A8B55D9CB06231052AD4C25804C2E3AF4
                0C20BDA50848726AA782231644000328230C0057CF8018EA5376E855A3458353
                1382B46129C0D71DD12604F1D2B613E1DD78765073A7EF0AC40828674DA563F9
                9A1B5C1BBE5762AFA019CC303A2B49A00CCF398C2A8BD74AA0EF0568864B1952
                8F50BC086C58E0CEB4454E6D3F1478697B53782F1E1D300190F0D46AAC67887A
                735090B5B8D856BBBA9A5973E32C67AD2BD3E2028BEAE012233A08951DC2A4F7
                F86232D117B44D40CC3581213E70A03954BFA331B87D7F7BB43ECCC94C08A3D8
                99C088A9F106C4DA71C66A816264A76EED62F7DD9326DA4A9D2E0B43D00A1B3A
                0032BE79A054D144E29E97A00600353A09082018E0435D97D8D6B7F68FBCB7FD
                64780FCB83B4D5134AB221ED2F24C67AF466C692B4ECCAAD29A0E6DE5DED5C56
                5162AF29BA8E2ECDCAA23C84154DB6C49F412B9B0986EA57365E5D34497EC18A
                3034C88D745C8EB536B7461ADE6B0C7ED6D0CD1DC34BA5DD76CE0440B22D090F
                43D33DFE4D6625F9B8CB6D25F2AA0AE8F28A89D6D955C5D69AB209D6D2825C3A
                CFE3B1B8645094C4943A5792E1A87F018D1FC1E4D6DD1FEBBDF02DDB7AA29D6D
                68E9624F1EEF8E9DF5B3A2B4311D180580992D09D5EF981A3439A7BD4BD59467
                82972CF03064BED346E44FCFA78B8A73A8DC1C972583B181BCAF148A42E46A80
                1F6E1BE0FACEF5C43A4251B1C717127ABEF509DDA8B0110303E9640D901E588A
                B4C6327E2C6056F5C5A82F6BD28052320BA92F16E2C9ED2FF99591698992F681
                681A00631D330B1AC933FD97B4B49379CDBF7C80F491E3BBFECEEBAF69697F64
                F33F6FC6A2B419BA5BD80000000049454E44AE426082}
            end
            object SpeedButton1: TSpeedButton
              Left = 254
              Top = 212
              Width = 50
              Height = 50
              Flat = True
              OnClick = SpeedButton1Click
            end
            object Edit10: TEdit
              Left = 9
              Top = 27
              Width = 233
              Height = 21
              TabOrder = 0
            end
            object Edit13: TEdit
              Left = 9
              Top = 83
              Width = 231
              Height = 21
              NumbersOnly = True
              TabOrder = 1
            end
            object Button21: TButton
              Left = 35
              Top = 124
              Width = 199
              Height = 50
              Caption = 'Editeaza'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -19
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentFont = False
              TabOrder = 2
              OnClick = Button21Click
            end
            object Button22: TButton
              Left = 33
              Top = 212
              Width = 201
              Height = 50
              Caption = 'Anuleaza'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -19
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentFont = False
              TabOrder = 3
              OnClick = Button22Click
            end
          end
        end
      end
      object Panel6: TPanel
        Left = 328
        Top = -6
        Width = 433
        Height = 479
        TabOrder = 1
        object DBGrid2: TDBGrid
          Left = 1
          Top = 1
          Width = 431
          Height = 477
          Hint = 'Click On Screen'
          Align = alClient
          DataSource = dm.dsqprodus
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
          OnDblClick = DBGrid2DblClick
          Columns = <
            item
              Expanded = False
              FieldName = 'PRODUSE_ID'
              Title.Caption = 'NR'
              Width = 38
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'COD_PRODUS'
              Title.Caption = 'COD PRODUS'
              Width = 104
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'DENUMIRE'
              Width = 170
              Visible = True
            end>
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'UNIT.MAS.'
      ImageIndex = 2
      object Panel7: TPanel
        Left = -4
        Top = -6
        Width = 261
        Height = 476
        TabOrder = 0
        object Button7: TButton
          Left = 32
          Top = 64
          Width = 185
          Height = 153
          Caption = 'Selecteaza'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = Button7Click
        end
      end
      object Panel8: TPanel
        Left = 256
        Top = -6
        Width = 505
        Height = 476
        TabOrder = 1
        object DBGrid3: TDBGrid
          Left = 1
          Top = 1
          Width = 503
          Height = 474
          Align = alClient
          DataSource = dm.DSQUM
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
          Columns = <
            item
              Expanded = False
              FieldName = 'UNIT_MASURA_ID'
              Title.Alignment = taCenter
              Title.Caption = 'Nr.'
              Width = 23
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'ABREVIERE'
              Title.Alignment = taCenter
              Title.Caption = 'Abrevieri'
              Width = 142
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'NUME'
              Title.Alignment = taCenter
              Title.Caption = 'Denumire'
              Width = 148
              Visible = True
            end>
        end
      end
    end
  end
end
